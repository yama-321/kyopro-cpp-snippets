// 区間set

using namespace std;

template <typename Color>
class range_set {
 public:
  using ll = long long;

  struct Node {
    ll l, r;
    mutable Color color;

    bool operator<(const Node& other) const { return l < other.l; }
  };

 private:
  set<Node> st;
  map<Color, ll> color_length;  // 各色の合計長
  ll total_length = 0;          // 全体の塗られている長さの合計

  // 色の長さを更新するヘルパー関数
  void update_length(const Color& c, ll len) {
    color_length[c] += len;
    if (color_length[c] == 0) {
      color_length.erase(c);
    }
    total_length += len;
  }

 public:
  range_set() = default;

  // [l, r] の色を削除する（無色にする）
  void erase(ll l, ll r) {
    if (l > r) return;

    auto it = st.upper_bound({l, numeric_limits<ll>::max(), Color{}});
    if (it != st.begin()) --it;

    vector<Node> to_add;

    while (it != st.end() && it->l <= r) {
      if (it->r < l) {
        ++it;
        continue;
      }

      ll nl = it->l, nr = it->r;
      Color nc = it->color;

      // 消去範囲からはみ出る左側・右側の残存部分を保持
      if (nl < l) {
        to_add.push_back({nl, l - 1, nc});
      }
      if (nr > r) {
        to_add.push_back({r + 1, nr, nc});
      }

      update_length(nc, -(nr - nl + 1));
      it = st.erase(it);
    }

    // 残った端の部分を再挿入
    for (const auto& node : to_add) {
      st.insert(node);
      update_length(node.color, node.r - node.l + 1);
    }
  }

  // [l, r] を色 c で塗りつぶす
  void assign(ll l, ll r, const Color& c) {
    if (l > r) return;

    // 指定領域内の既存色を消去
    erase(l, r);

    // 左隣の区間が同じ色なら結合
    auto it = st.lower_bound({l, numeric_limits<ll>::min(), Color{}});
    if (it != st.begin()) {
      auto prev_it = prev(it);
      if (prev_it->r + 1 == l && prev_it->color == c) {
        l = prev_it->l;
        update_length(prev_it->color, -(prev_it->r - prev_it->l + 1));
        st.erase(prev_it);
      }
    }

    // 右隣の区間が同じ色なら結合
    it = st.lower_bound({r + 1, numeric_limits<ll>::min(), Color{}});
    if (it != st.end() && it->l == r + 1 && it->color == c) {
      r = it->r;
      update_length(it->color, -(it->r - it->l + 1));
      st.erase(it);
    }

    // 拡張された区間を挿入
    st.insert({l, r, c});
    update_length(c, r - l + 1);
  }

  // 指定した座標 x の色を取得する（無色の場合は std::nullopt を返す）
  std::optional<Color> get_color(ll x) const {
    // x より後に始まる最初の区間を検索
    auto it = st.upper_bound({x, numeric_limits<ll>::max(), Color{}});

    // 直前の区間が存在すれば、その区間に x が含まれるか確認
    if (it != st.begin()) {
      --it;
      if (it->l <= x && x <= it->r) {
        return it->color;
      }
    }

    return std::nullopt;  // 無色
  }

// 地点 x を含む、連続して同じ色が塗られている区間ノード {l, r, color} を返す（無色の場合は std::nullopt）
  std::optional<Node> get_node(ll x) const {
    auto it = st.upper_bound({x, numeric_limits<ll>::max(), Color{}});

    if (it != st.begin()) {
      --it;
      if (it->l <= x && x <= it->r) {
        return *it;
      }
    }

    return std::nullopt;  // 無色
  }

  // [l, r] の範囲に色が部分的にでも塗られているか判定
  bool is_colored_any(ll l, ll r) const {
    if (l > r) return false;

    auto it = st.lower_bound({l, numeric_limits<ll>::min(), Color{}});
    if (it != st.end() && it->l <= r) return true;
    if (it != st.begin()) {
      --it;
      if (it->r >= l) return true;
    }
    return false;
  }

  // [l, r] の範囲が単一の同じ色で完全に塗られているか判定
  bool is_colored_same(ll l, ll r) const {
    if (l > r) return true;

    // l を含む可能性のある区間を二分探索
    auto it = st.upper_bound({l, numeric_limits<ll>::max(), Color{}});
    if (it == st.begin()) return false;
    --it;

    // l から始まり r 以上まで「1つの区間」で覆われていれば OK
    return (it->l <= l && it->r >= r);
  }

  // 特定の色の塗られている合計長さを取得
  ll get_length_of_color(const Color& c) const {
    auto it = color_length.find(c);
    return (it != color_length.end()) ? it->second : 0LL;
  }

  // 塗られている全色の合計長さを取得
  ll get_total_length() const { return total_length; }

  // 内部の set を参照可能にする（デバッグや巡回用）
  const set<Node>& get_set() const { return st; }
};

// 使い方

// ・assign(l, r, color)
//   区間[l, r]を指定したcolorで塗りつぶす(既存の色は上書き)

// ・erase(l, r)
//   区間[l, r]の色を削除

// ・get_color(x)
//   地点xの現在の色を取得(無色の場合はstd::nullopt)
//   ※返り値はoptionalオブジェクト
//   (返却値cが真なら色取得は*c、偽なら地点xは無色)

// ・get_node(x)
//   地点xから連続して同じ色が塗られている区間ノード{l, r, color}を取得
//   ※返り値はoptionalオブジェクト
//   (返却値がnodeが真ならノード取得は*node、偽なら地点xは無色)

// ・is_colored_any(l, r)
//   区間[l, r]に1箇所以上色が塗られているか判定

// ・is_colored_same(l, r)
//   区間[l, r]に完全に同じ色で塗られているか判定

// ・get_total_length()
//   何等かの色が塗られている全体の長さを取得

// ・get_length_of_color(c)
//   色cが塗られている合計の長さを取得

// ・get_set()
//   内部の区間を定数参照

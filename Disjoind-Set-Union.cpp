// Union-Find
// 削除機能付き(cut(a)で要素aを孤立化)
// それ以外は基本的にACLのdsuと同じ(groups()の機能は無し)
struct DSU {
  using ll = long long;
  std::vector<ll> Parent, Size, Real_Node;
  ll num_groups;
  DSU(ll n) {
    Parent.resize(n, 0);
    Size.resize(n, 1);
    Real_Node.resize(n, 0);
    for (ll i = 0; i < n; i++) Parent[i] = Real_Node[i] = i;
    num_groups = n;
  }
  ll leader_idx(ll a) {
    if (Parent[a] == a) return a;
    return Parent[a] = leader_idx(Parent[a]);
  }
  ll leader(ll a) { return leader_idx(Real_Node[a]); }
  bool merge(ll a, ll b) {
    ll x = leader(a), y = leader(b);
    if (x == y) return false;
    if (Size[x] < Size[y]) std::swap(x, y);
    Parent[y] = x;
    Size[x] += Size[y];
    num_groups--;
    return true;
  }
  void cut(ll a) {
    if (Size[leader(a)] == 1) return;
    ll sz = Parent.size();
    Size[leader(a)]--;
    Parent.push_back(sz);
    Size.push_back(1);
    Real_Node[a] = sz;
    num_groups++;
  }
  bool same(ll a, ll b) { return leader(a) == leader(b); }
  ll size(ll a) { return Size[leader(a)]; }
  ll count_groups() { return num_groups; }
};

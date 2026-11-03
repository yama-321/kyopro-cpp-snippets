// 偏角ソート
// 1. 上半平面（+x軸含む）にあるか判定
inline bool is_upper(ll x, ll y) {
    return y > 0 || (y == 0 && x >= 0);
}

// 2. 偏角比較関数 (a < b なら true)
//   ・+x軸から反時計回り [0, 2π) の順
//   ・原点 (0,0) は最後
//   ・同偏角なら原点から近い順
inline bool cmp_arg(pair<ll, ll> a, pair<ll, ll> b) {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    bool a0 = (ax == 0 && ay == 0);
    bool b0 = (bx == 0 && by == 0);
    if (a0 || b0) return a0 < b0; // 原点は最後 (a0=1, b0=0 なら false)

    bool ha = is_upper(ax, ay);
    bool hb = is_upper(bx, by);
    if (ha != hb) return ha > hb; // 上半平面(true)が先

    // 同じ半平面内なら外積で判定 (a x b > 0 なら a が反時計回りで先)
    __int128 cr = (__int128)ax * by - (__int128)ay * bx;
    if (cr != 0) return cr > 0;

    // 同偏角なら原点からの距離昇順 (x^2 + y^2)
    return (__int128)ax * ax + ay * ay < (__int128)bx * bx + by * by;
}

// 3. 配列の偏角ソート
inline void sort_by_arg(vector<pair<ll, ll>>& pts) {
    sort(pts.begin(), pts.end(), cmp_arg);
}

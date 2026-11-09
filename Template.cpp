// 共通テンプレート
// https://github.com/yama-321/kyopro-cpp-snippets
// インクルード
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// 型エイリアス
using ll = long long;
using ld = long double;
using int128 = __int128_t;
template <typename T>
using vec = vector<T>;
using mint998 = modint998244353;
using mint107 = modint1000000007;
// 定数
const ll INF = 1LL << 30;
const ll LINF = 1LL << 60;
// 関数形式マクロ
#define rep1(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, rep2, rep1, 0, )(__VA_ARGS__)
#define rrep1(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define rrep2(i, a, b) for (ll i = (ll)(b) - 1; i >= (ll)(a); --i)
#define GET_RREP(_1, _2, _3, NAME, ...) NAME
#define rrep(...) GET_RREP(__VA_ARGS__, rrep2, rrep1, 0, )(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rall(x) (x).rbegin(), (x).rend()
#define self(f) this auto&& f
// clang-format off
// テンプレート関数
template <class T> T floor_div(T a, T b) { return a / b - ((a ^ b) < 0 && a % b != 0); }
template <class T> T ceil_div(T a, T b) { return a / b + ((a ^ b) > 0 && a % b != 0); }
template <class T = bool> inline void Yes(T b = true) { cout << (b ? "Yes\n" : "No\n"); }
inline void No() { cout << "No\n"; }
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template <class H, class... T>
void print(const H& h, const T&... t) {cout << h; ((cout << ' ' << t), ...); cout << '\n'; }
inline void print() { cout << '\n'; }
template<class... A> void print_sp(const A&... a) { ((cout << a << ' '), ...); }
inline void print_sp() { cout << ' '; }
template <class H, class... T>
void print_nn(const H& h, const T&... t) {cout << h; ((cout << ' ' << t), ...); }
template <class... A> void put(const A&... a) { (cout << ... << a); }
// デバッグ用関数
// ※コンテナはvector、pair、set、mapのみ対応
#ifdef _GLIBCXX_DEBUG
template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p);
template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
template <class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& s);
template <class K, class V> std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m);

template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) os << (i ? " " : "") << v[i];
    return os << "]";
}
template <class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool f = 1;
    for (auto& x : s) os << (f ? "" : " ") << x, f = 0;
    return os << "}";
}
template <class K, class V> std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool f = 1;
    for (auto& [k, v] : m) os << (f ? "" : " ") << k << ": " << v, f = 0;
    return os << "}";
}
#define debug(...) \
    std::cerr << "[" << #__VA_ARGS__ << "]:", \
    [](auto... a) { std::cerr << std::boolalpha; ((std::cerr << " " << a), ...); std::cerr << "\n"; } \
    (__VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif
// clang-format on

void solve(){
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  
  int t = 1;
  // cin >> t;
  while(t--) solve();
  
  return 0;
}

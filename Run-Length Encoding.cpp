// ランレングス圧縮
// 配列A = rle_build(配列B);により、配列Bをランレングス圧縮した結果を配列Aに格納
// 配列Aは[任意の型, 圧縮数]となっていることに注意
auto rle_build = [](const auto& a) {
  using T = std::decay_t<decltype(a[0])>;
  vector<pair<T, ll>> res;
  ll n = a.size();
  if (n == 0) return res;

  ll cnt = 1;
  rep(i, n) {
    if (i + 1 < n && a[i] == a[i + 1]) {
      cnt++;
    } else {
      res.push_back({a[i], cnt});
      cnt = 1;
    }
  }
  return res;
};

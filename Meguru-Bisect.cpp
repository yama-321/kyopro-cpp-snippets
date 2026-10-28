// めぐる式二分探索
auto meguru_bisect = [&]() -> ll {
  // 判定関数はその都度変更
  auto is_ok = [&](ll x) -> bool {};
  // ngとokの初期値はその都度変更
  ll ng = -1;
  ll ok = LINF;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (is_ok(mid))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
};

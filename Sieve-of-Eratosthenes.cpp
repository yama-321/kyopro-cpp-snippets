// エラトステネスの篩
// auto 配列A = sieve_build(N);により、N以下の素数判定テーブル（boolの配列）Aを宣言
auto sieve_build = [](ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (ll i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
};

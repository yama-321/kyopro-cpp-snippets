// 非負の重み付きグラフにおけるダイクストラ法
// 最小ヒープの宣言から最短経路の算出まで
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
pq.push({0, 0});  // スタート地点のpush、その都度変更
vector<ll> cost(n, LINF);
cost[0] = 0;  // スタート地点のコスト、その都度変更
while (!pq.empty()) {
  auto [c, u] = pq.top();
  pq.pop();
  if (c > cost[u]) continue;
  for (auto [w, to] : g[u]) {  // [重さ, 頂点]の順番になっていることに注意
    ll nc = c + w;
    if (nc < cost[to]) {
      cost[to] = nc;
      pq.push({nc, to});
    }
  }
}

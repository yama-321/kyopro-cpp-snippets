// Union-Find
// 基本的にACLのdsuと同じ(groups()の機能は無し)
struct DSU {
  std::vector<int> Parent, Size;
  int num_groups;
  DSU(int n) {
    Parent.resize(n, 0);
    Size.resize(n, 1);
    for (int i = 0; i < n; i++) Parent[i] = i;
    num_groups = n;
  }
  int leader(int a) {
    if (Parent[a] == a) return a;
    return Parent[a] = leader(Parent[a]);
  }
  bool merge(int a, int b) {
    int x = leader(a), y = leader(b);
    if (x == y) return false;
    if (Size[x] < Size[y]) std::swap(x, y);
    Parent[y] = x;
    Size[x] += Size[y];
    num_groups--;
    return true;
  }
  bool same(int a, int b) { return leader(a) == leader(b); }
  int size(int a) { return Size[leader(a)]; }
  int count_groups() { return num_groups; }
};

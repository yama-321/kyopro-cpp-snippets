struct S { ll val; int sz; };
using F = ll;
const F ID = LINF;

S op(S a, S b){ return {a.val + b.val, a.sz + b.sz}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return f == ID ? x : S{f * x.sz, x.sz}; }
F composition(F f, F g){ return f == ID ? g : f; }
F id(){ return ID; }

// {a[i], 1}の配列vector<S> init(n)を引数として渡す

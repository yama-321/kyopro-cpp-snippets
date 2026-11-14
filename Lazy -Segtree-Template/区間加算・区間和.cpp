struct S { ll val; int sz; };
using F = ll;

S op(S a, S b){ return {a.val + b.val, a.sz + b.sz}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.val + f * x.sz, x.sz}; }
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

// {a[i], 1}の配列vector<S> init(n)を引数として渡す

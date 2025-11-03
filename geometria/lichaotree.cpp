#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Line {
    int a, b;
    Line(int _a = 0, int _b = LLONG_MIN) : a(_a), b(_b) {}
    int eval(int x) const { return a*x + b; }
};

const int MAXN = 100005; // rango de x (0 <= x <= 1e5)
const int TREE_SIZE = 4 * MAXN;

struct LiChaoTree {
    Line tree[TREE_SIZE];
    int l_bound, r_bound;

    LiChaoTree(int _l, int _r) : l_bound(_l), r_bound(_r) {
        for (int i = 0; i < TREE_SIZE; i++) tree[i] = Line();
    }

    void insert(Line nueva, int v = 1, int l = -1, int r = -1) {
        if (l == -1) l = l_bound;
        if (r == -1) r = r_bound;
        int m = (l + r) / 2;
        bool leftBetter = nueva.eval(l) > tree[v].eval(l);
        bool midBetter  = nueva.eval(m) > tree[v].eval(m);
        if (midBetter) swap(tree[v], nueva);
        if (l == r) return;
        if (leftBetter != midBetter) insert(nueva, v*2, l, m);
        else insert(nueva, v*2+1, m+1, r);
    }

    int query(int x, int v = 1, int l = -1, int r = -1) const {
        if (l == -1) l = l_bound;
        if (r == -1) r = r_bound;
        int res = tree[v].eval(x);
        if (l == r) return res;
        int m = (l + r) / 2;
        if (x <= m) res = max(res, query(x, v*2, l, m));
        else res = max(res, query(x, v*2+1, m+1, r));
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    LiChaoTree tree(0, 100000); // rango de x dado por el problema
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            tree.insert(Line(a, b));
        } else {
            int x; cin >> x;
            cout << tree.query(x) << "\n";
        }
    }
}


//con doubles

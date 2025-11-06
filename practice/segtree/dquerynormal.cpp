#include "bits/stdc++.h"
#define int long long
using namespace std;

struct Node {
    int rango;
    Node(int x) : rango(x) {}
    Node() : rango(0) {}
};

struct segtree {
    int n;
    vector<Node> tree;
    Node neutral;

    segtree(int nn, Node neutral) : neutral(neutral) {
        n = nn;
        int size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, neutral); 
    }

    Node combine(Node a, Node b) {
        return Node(a.rango + b.rango);
    }

    void update(int i, int sl, int sr, int pos, Node diff) {
        if (sl == sr) {
            tree[i].rango = diff.rango;
        } else {
            int mid = (sl + sr) / 2;
            if (pos <= mid) {
                update(2 * i + 1, sl, mid, pos, diff);
            } else {
                update(2 * i + 2, mid + 1, sr, pos, diff);
            }
            tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void update(int pos, Node diff) {
        update(0, 0, n - 1, pos, diff);
    }

    Node query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return tree[i];
        } else if (sr < l || r < sl) {
            return neutral; 
        } else {
            int mid = (sl + sr) / 2;
            Node a = query(2 * i + 1, sl, mid, l, r);
            Node b = query(2 * i + 2, mid + 1, sr, l, r);
            return combine(a, b);
        }
    }

    Node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

signed main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> q;
    map<int, vector<pair<int, int>>> querys;
    vector<int> respuestas(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        querys[r].push_back({l, i});
    }

    vector<int> sufijos(n + 1);
    segtree seg(n + 1, Node(0));
    map<int, int> ultimaAparicion;

    for (int i = 1; i <= n; i++) {
        int x = arr[i - 1];
        if (ultimaAparicion[x] > 0) {
            seg.update(ultimaAparicion[x], Node(0));
        }
        seg.update(i, Node(1));
        ultimaAparicion[x] = i;

        for (auto con : querys[i]) {
            auto [left, idx] = con;
            respuestas[idx] = seg.query(left, i).rango;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << respuestas[i] << '\n';
    }
}

#include <iostream>
#include <algorithm>

using namespace std;

struct QuadNode {
    long long val = 0;
    long long lazy = 0;
    QuadNode *tl = nullptr, *tr = nullptr, *bl = nullptr, *br = nullptr;
};

struct DynamicSegTree2DLazy {
    int n, m;
    QuadNode* root;

    DynamicSegTree2DLazy(int n, int m) : n(n), m(m) {
        root = new QuadNode();
    }

    long long area(int r1, int r2, int c1, int c2) {
        return 1LL * (r2 - r1 + 1) * (c2 - c1 + 1);
    }

    void apply_lazy(QuadNode* u, int r1, int r2, int c1, int c2, long long v) {
        if (!u) return;
        u->val += v * area(r1, r2, c1, c2);
        u->lazy += v;
    }

    void push(QuadNode* u, int r1, int r2, int c1, int c2) {
        if (!u || u->lazy == 0) return;
        int mr = (r1 + r2) / 2;
        int mc = (c1 + c2) / 2;

        // Propaga la marca a los 4 cuadrantes (creando los nodos solo si es necesario)
        if (r1 <= mr && c1 <= mc) {
            if (!u->tl) u->tl = new QuadNode();
            apply_lazy(u->tl, r1, mr, c1, mc, u->lazy);
        }
        if (r1 <= mr && mc + 1 <= c2) {
            if (!u->tr) u->tr = new QuadNode();
            apply_lazy(u->tr, r1, mr, mc + 1, c2, u->lazy);
        }
        if (mr + 1 <= r2 && c1 <= mc) {
            if (!u->bl) u->bl = new QuadNode();
            apply_lazy(u->bl, mr + 1, r2, c1, mc, u->lazy);
        }
        if (mr + 1 <= r2 && mc + 1 <= c2) {
            if (!u->br) u->br = new QuadNode();
            apply_lazy(u->br, mr + 1, r2, mc + 1, c2, u->lazy);
        }
        u->lazy = 0;
    }

    void update(QuadNode* u, int r1, int r2, int c1, int c2, int qr1, int qr2, int qc1, int qc2, long long v) {
        if (qr1 > r2 || qr2 < r1 || qc1 > c2 || qc2 < c1) return;
        
        // Cobertura completa del cuadrante
        if (qr1 <= r1 && r2 <= qr2 && qc1 <= c1 && c2 <= qc2) {
            apply_lazy(u, r1, r2, c1, c2, v);
            return;
        }

        push(u, r1, r2, c1, c2);
        int mr = (r1 + r2) / 2;
        int mc = (c1 + c2) / 2;

        if (qr1 <= mr && qc1 <= mc) {
            if (!u->tl) u->tl = new QuadNode();
            update(u->tl, r1, mr, c1, mc, qr1, qr2, qc1, qc2, v);
        }
        if (qr1 <= mr && qc2 > mc) {
            if (!u->tr) u->tr = new QuadNode();
            update(u->tr, r1, mr, mc + 1, c2, qr1, qr2, qc1, qc2, v);
        }
        if (qr2 > mr && qc1 <= mc) {
            if (!u->bl) u->bl = new QuadNode();
            update(u->bl, mr + 1, r2, c1, mc, qr1, qr2, qc1, qc2, v);
        }
        if (qr2 > mr && qc2 > mc) {
            if (!u->br) u->br = new QuadNode();
            update(u->br, mr + 1, r2, mc + 1, c2, qr1, qr2, qc1, qc2, v);
        }

        u->val = (u->tl ? u->tl->val : 0) +
                 (u->tr ? u->tr->val : 0) +
                 (u->bl ? u->bl->val : 0) +
                 (u->br ? u->br->val : 0);
    }

    long long query(QuadNode* u, int r1, int r2, int c1, int c2, int qr1, int qr2, int qc1, int qc2) {
        if (!u || qr1 > r2 || qr2 < r1 || qc1 > c2 || qc2 < c1) return 0;
        if (qr1 <= r1 && r2 <= qr2 && qc1 <= c1 && c2 <= qc2) return u->val;

        push(u, r1, r2, c1, c2);
        int mr = (r1 + r2) / 2;
        int mc = (c1 + c2) / 2;
        long long res = 0;

        if (u->tl) res += query(u->tl, r1, mr, c1, mc, qr1, qr2, qc1, qc2);
        if (u->tr) res += query(u->tr, r1, mr, mc + 1, c2, qr1, qr2, qc1, qc2);
        if (u->bl) res += query(u->bl, mr + 1, r2, c1, mc, qr1, qr2, qc1, qc2);
        if (u->br) res += query(u->br, mr + 1, r2, mc + 1, c2, qr1, qr2, qc1, qc2);

        return res;
    }

    void update(int r1, int r2, int c1, int c2, long long v) {
        update(root, 0, n - 1, 0, m - 1, r1, r2, c1, c2, v);
    }

    long long query(int r1, int r2, int c1, int c2) {
        return query(root, 0, n - 1, 0, m - 1, r1, r2, c1, c2);
    }
};
//en compe averiguo como funciona
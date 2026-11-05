#include <vector>
#include <algorithm>

using namespace std;

template <typename Node>
struct SegTree2D {
    int n, m;
    vector<vector<Node>> tree;

    SegTree2D(int n, int m) : n(n), m(m) {
        tree.assign(4 * n, vector<Node>(4 * m));
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int r, int c, const Node& val) {
        if (ly == ry) {
            if (lx == rx) {
                tree[vx][vy] = val;
            } else {
                tree[vx][vy] = Node::merge(tree[2 * vx][vy], tree[2 * vx + 1][vy]);
            }
        } else {
            int my = (ly + ry) / 2;
            if (c <= my)
                update_y(vx, lx, rx, 2 * vy, ly, my, r, c, val);
            else
                update_y(vx, lx, rx, 2 * vy + 1, my + 1, ry, r, c, val);
            
            tree[vx][vy] = Node::merge(tree[vx][2 * vy], tree[vx][2 * vy + 1]);
        }
    }

    void update(int vx, int lx, int rx, int r, int c, const Node& val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (r <= mx)
                update(2 * vx, lx, mx, r, c, val);
            else
                update(2 * vx + 1, mx + 1, rx, r, c, val);
        }
        update_y(vx, lx, rx, 1, 0, m - 1, r, c, val);
    }

    void update(int r, int c, const Node& val) {
        update(1, 0, n - 1, r, c, val);
    }

    Node query_y(int vx, int vy, int ly, int ry, int c1, int c2) {
        if (c1 > ry || c2 < ly) return Node(); // Elemento neutro (identidad)
        if (c1 <= ly && ry <= c2) return tree[vx][vy];
        int my = (ly + ry) / 2;
        return Node::merge(query_y(vx, 2 * vy, ly, my, c1, c2),
                           query_y(vx, 2 * vy + 1, my + 1, ry, c1, c2));
    }

    Node query(int vx, int lx, int rx, int r1, int r2, int c1, int c2) {
        if (r1 > rx || r2 < lx) return Node(); // Elemento neutro (identidad)
        if (r1 <= lx && rx <= r2) return query_y(vx, 1, 0, m - 1, c1, c2);
        int mx = (lx + rx) / 2;
        return Node::merge(query(2 * vx, lx, mx, r1, r2, c1, c2),
                           query(2 * vx + 1, mx + 1, rx, r1, r2, c1, c2));
    }
    Node query(int r1, int r2, int c1, int c2) {
        return query(1, 0, n - 1, r1, r2, c1, c2);
    }
};
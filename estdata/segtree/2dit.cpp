#include <vector>
#include <algorithm>

using namespace std;

template <typename Node>
struct SegTree2D {
    int n, m;
    vector<vector<Node>> tree;

    SegTree2D(int n, int m) : n(n), m(m) {
        tree.assign(2 * n, vector<Node>(2 * m));
    }

    // Actualización puntual en (r, c)
    void update(int r, int c, const Node& val) {
        int x = r + n;
        int y0 = c + m;

        // 1. Actualizar la celda y sus ancestros en Y dentro de la fila hoja x
        tree[x][y0] = val;
        for (int y = y0 >> 1; y > 0; y >>= 1) {
            tree[x][y] = Node::merge(tree[x][y << 1], tree[x][(y << 1) | 1]);
        }

        // 2. Propagar hacia arriba en los ancestros de X
        for (x >>= 1; x > 0; x >>= 1) {
            for (int y = y0; y > 0; y >>= 1) {
                tree[x][y] = Node::merge(tree[x << 1][y], tree[(x << 1) | 1][y]);
            }
        }
    }

    // Consulta 1D en el rango de columnas [c1, c2] para un nodo X dado
    Node query1D(int x, int c1, int c2) {
        Node resL, resR;
        for (int l = c1 + m, r = c2 + m + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = Node::merge(resL, tree[x][l++]);
            if (r & 1) resR = Node::merge(tree[x][--r], resR);
        }
        return Node::merge(resL, resR);
    }

    // Consulta 2D en la submatriz [r1, r2] x [c1, c2] (inclusivos)
    Node query(int r1, int r2, int c1, int c2) {
        Node resL, resR;
        for (int l = r1 + n, r = r2 + n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = Node::merge(resL, query1D(l++, c1, c2));
            if (r & 1) resR = Node::merge(query1D(--r, c1, c2), resR);
        }
        return Node::merge(resL, resR);
    }
};
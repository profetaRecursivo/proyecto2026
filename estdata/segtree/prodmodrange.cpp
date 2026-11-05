#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// 1. Totiente de Euler
ll phi(ll x) {
    if (x == 1) return 1;
    ll res = x, t = x;
    for (ll p = 2; p * p <= t; ++p) {
        if (t % p == 0) {
            while (t % p == 0) t /= p;
            res = res / p * (p - 1);
        }
    }
    if (t > 1) res = res / t * (t - 1);
    return res;
}

// 2. Exponenciación Binaria
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll phi_m;

// 3. Tu Segment Tree Adaptado
struct Node {
    ll mod;
    ll cap;
    Node(ll m = 1, ll c = 1) : mod(m), cap(c) {} // Neutro por defecto
};

Node merge(const Node& a, const Node& b) {
    Node res;
    res.mod = (a.mod * b.mod) % phi_m;
    ll prod_cap = a.cap * b.cap;
    res.cap = min(prod_cap, phi_m);
    return res;
}

const int tam = 100010;
ll arr[tam];
Node tr[4 * tam];

void build(int b, int e, int node) {
    if (b == e) {
        tr[node] = Node(arr[b] % phi_m, min(arr[b], phi_m));
        return;
    }
    int l = node * 2, r = l + 1, mid = (b + e) / 2;
    build(b, mid, l);
    build(mid + 1, e, r);
    tr[node] = merge(tr[l], tr[r]);
}

void update(int b, int e, int node, int pos, ll value) {
    if (b == e) {
        tr[node] = Node(value % phi_m, min(value, phi_m));
        return;
    }
    int mid = (b + e) / 2, l = node * 2, r = l + 1;
    if (pos <= mid) update(b, mid, l, pos, value);
    else update(mid + 1, e, r, pos, value);
    tr[node] = merge(tr[l], tr[r]);
}

Node query(int b, int e, int node, int i, int j) {
    if (j < i) return Node(1, 1);
    if (i <= b && e <= j) return tr[node];
    int mid = (b + e) / 2, l = node * 2, r = l + 1;
    if (j <= mid) return query(b, mid, l, i, j);
    if (i > mid) return query(mid + 1, e, r, i, j);
    return merge(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    ll m;
    if (!(cin >> n >> q >> m)) return 0;

    for (int i = 0; i < n; i++) cin >> arr[i];

    // Calculamos phi(M) antes de construir el árbol
    phi_m = phi(m);
    build(0, n - 1, 1);

    while (q--) {
        char type;
        cin >> type;
        if (type == 'u') {
            int k; ll v;
            cin >> k >> v;
            arr[k] = v;
            update(0, n - 1, 1, k, v);
        } else {
            int l, r;
            cin >> l >> r;
            if (l == r) {
                cout << arr[l] % m << "\n";
            } else {
                // Consultamos el producto del exponente en el rango [l+1, r]
                Node res = query(0, n - 1, 1, l + 1, r);
                
                // Aplicamos la reducción de exponente de Euler
                ll exp = res.mod + (res.cap >= phi_m ? phi_m : 0);
                
                // Exponenciación binaria para la respuesta final
                cout << power(arr[l], exp, m) << "\n";
            }
        }
    }
}
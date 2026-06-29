int arr[tam];
int maxi[4 * tam];
int visibles[4 * tam];
int calc(int nodo, int izq, int der, int val) {
    if (maxi[nodo] <= val) return 0;
    if (izq == der) return 1;
    int mitad = (izq + der) / 2;
    int hijo_izq = 2 * nodo;
    int hijo_der = 2 * nodo + 1;
    if (maxi[hijo_izq] <= val) {
        return calc(hijo_der, mitad + 1, der, val);
    } else {
        return calc(hijo_izq, izq, mitad, val) + visibles[nodo] - visibles[hijo_izq];
    }
}
void construir(int nodo, int izq, int der) {
    if (izq == der) {
        maxi[nodo] = arr[izq];
        visibles[nodo] = 1;
        return;
    }
    int mitad = (izq + der) / 2;
    int hijo_izq = 2 * nodo;
    int hijo_der = 2 * nodo + 1;
    construir(hijo_izq, izq, mitad);
    construir(hijo_der, mitad + 1, der);
    maxi[nodo] = max(maxi[hijo_izq], maxi[hijo_der]);
    visibles[nodo] = visibles[hijo_izq] + calc(hijo_der, mitad + 1, der, maxi[hijo_izq]);
}
void update(int nodo, int izq, int der, int pos, int val) {
    if (izq == der) {
        maxi[nodo] = val;
        visibles[nodo] = 1;
        return;
    }
    int mitad = (izq + der) / 2;
    int hijo_izq = 2 * nodo;
    int hijo_der = 2 * nodo + 1;
    if (pos <= mitad) {
        update(hijo_izq, izq, mitad, pos, val);
    } else {
        update(hijo_der, mitad + 1, der, pos, val);
    }
    maxi[nodo] = max(maxi[hijo_izq], maxi[hijo_der]);
    visibles[nodo] = visibles[hijo_izq] + calc(hijo_der, mitad + 1, der, maxi[hijo_izq]);
}

int query(int nodo, int izq, int der, int q_izq, int q_der, int &max_actual) {
    if (q_izq <= izq and der <= q_der) {
        int res = calc(nodo, izq, der, max_actual);
        max_actual = max(max_actual, maxi[nodo]);
        return res;
    }
    int mitad = (izq + der) / 2;
    int hijo_izq = 2 * nodo;
    int hijo_der = 2 * nodo + 1;
    int res = 0;
    if (q_izq <= mitad) {
        res += query(hijo_izq, izq, mitad, q_izq, q_der, max_actual);
    }
    if (q_der > mitad) {
        res += query(hijo_der, mitad + 1, der, q_izq, q_der, max_actual);
    }
    return res;
}
void solve() {
    int n, q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    construir(1, 1, n);
    while (q--) {
        int tipo;
        if (tipo == 1) {
            int pos, val;cin >> pos >> val;
            update(1, 1, n, pos, val);
            arr[pos] = val;
        } else {
            int a, b;cin >> a >> b;
            int max_actual = 0;
            cout << query(1, 1, n, a, b, max_actual) << '\n';
        }
    }
}
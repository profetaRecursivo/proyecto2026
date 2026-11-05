int contar_ciclos(const vector<int>& a) {
    int n = a.size();
    vector<bool> vis(n, false);
    int ciclos = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ciclos++;
            int actual = i;
            while (!vis[actual]) {
                vis[actual] = true;
                actual = a[actual] - 1;
            }
        }
    }
    return ciclos;
}
int paridad(const vector<int>& a) {
    int n = a.size();
    int c = contar_ciclos(a);
    return (n - c) % 2;
}

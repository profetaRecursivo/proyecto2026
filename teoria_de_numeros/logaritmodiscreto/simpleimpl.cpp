//encuentra el minimo x para el cual a^x _= b mod m solo funciona con a y m coprimos
int solve(int a, int b, int m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;
    map<int, int> vals;
    for (int p = 1; p <= n; ++p)
        vals[expmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (expmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
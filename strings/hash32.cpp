struct Hash {
    const ull MOD1 = 1000000007ULL;
    const ull MOD2 = 1000000009ULL;
    const ull P1 = 1777771ULL;
    const ull P2 = 19260817ULL;

    vector<ull> h1, h2, pi1, pi2;

    Hash(const string &s) {
        int n = sz(s);
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        pi1.assign(n + 1, 1); pi2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            h1[i] = (h1[i-1] * P1 + s[i-1]) % MOD1;
            h2[i] = (h2[i-1] * P2 + s[i-1]) % MOD2;
            pi1[i] = (pi1[i-1] * P1) % MOD1;
            pi2[i] = (pi2[i-1] * P2) % MOD2;
        }
    }

    pair<ull, ull> get(int l, int r) {
        ull x1 = (h1[r] + MOD1 - (h1[l-1] * pi1[r-l+1]) % MOD1) % MOD1;
        ull x2 = (h2[r] + MOD2 - (h2[l-1] * pi2[r-l+1]) % MOD2) % MOD2;
        return {x1, x2};
    }
};
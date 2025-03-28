struct FT2D {
    vector<vector<ll>> bit;
    int n, m;

    FT2D(int a, int b) {
        n = a;
        m = b;
        bit.assign(n + 1, vector<ll>(m + 1, 0));
    }

    void update(int x, int y, ll delta) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                bit[i][j] += delta;
    }

    ll query(int x, int y) {
        ll sum = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                sum += bit[i][j];
        return sum;
    }

    ll query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

void set(int x, int y, ll value) {
    ll delta = value - mat[x][y];
    mat[x][y] = value; 
    update(x, y, delta);
}

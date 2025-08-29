//para operaciones que no sean idempotentes
//querys en O(1)
template<typename T>
struct DST {
    int n, size, maxlev;
    T e; 
    vector<T> A;
    vector<vector<T>> table;
    function<T(T,T)> F;

    DST(const vector<T>& arr, T neutral, function<T(T,T)> op) {
        //pasarle lambda asi:
        //auto f = [parametro extra como mod](int a, int b){
        //  operacion return a^b;
        //}
        A.resize(sz(arr));
        copy(arr.begin(), arr.end(), A.begin());
        e = neutral;
        F = op;
        n = sz(A);
        maxlev = 32 - __builtin_clz(n) - 1;
        size = 1 << maxlev;
        if (size != n) size <<= 1, ++maxlev;
        table.assign(maxlev + 1, vector<T>(size, e));
        build(0, 0, size);
    }

    void build(int level, int l, int r) {
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        table[level][m] = A[m];
        for (int i = m - 1; i >= l; i--)
            table[level][i] = F(A[i], table[level][i + 1]);
        if (m + 1 < r) {
            table[level][m + 1] = A[m + 1];
            for (int i = m + 2; i < r; i++)
                table[level][i] = F(table[level][i - 1], A[i]);
        }
        build(level + 1, l, m);
        build(level + 1, m, r);
    }

    T query(int x, int y) {
        if (x == y) return A[x];
        int k2 = 32 - __builtin_clz(x ^ y) - 1;
        int lev = maxlev - 1 - k2;
        T ans = table[lev][x];
        if (y & ((1 << k2) - 1))
            ans = F(ans, table[lev][y]);
        return ans;
    }
};
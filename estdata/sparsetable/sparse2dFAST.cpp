//es rapida por no declarar las matrices table a cada rato
//tampoco tan rapida en la practica, pero mejor 
//que la anterior
struct SparseTable2D {
    static const int maxN = 505;       // tamaño máximo de la matriz
    static const int LOG = 10;         // ceil(log2(maxN))
    int table[maxN][maxN][LOG][LOG];   // tabla estática
    int n, m;

    inline int log2int(int x) { return 31 - __builtin_clz(x); }

    void build(const vector<vector<int>> &matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int K = log2int(n) + 1;
        int L = log2int(m) + 1;


        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                table[i][j][0][0] = matrix[i][j];

        for (int k = 1; k < K; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                for (int j = 0; j < m; j++)
                    table[i][j][k][0] = max(table[i][j][k - 1][0],
                                             table[i + (1 << (k - 1))][j][k - 1][0]);


        for (int l = 1; l < L; l++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j + (1 << l) <= m; j++)
                    table[i][j][0][l] = max(table[i][j][0][l - 1],
                                             table[i][j + (1 << (l - 1))][0][l - 1]);

        for (int k = 1; k < K; k++)
            for (int l = 1; l < L; l++)
                for (int i = 0; i + (1 << k) <= n; i++)
                    for (int j = 0; j + (1 << l) <= m; j++)
                        table[i][j][k][l] = max({
                            table[i][j][k - 1][l - 1],
                            table[i + (1 << (k - 1))][j][k - 1][l - 1],
                            table[i][j + (1 << (l - 1))][k - 1][l - 1],
                            table[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1]
                        });
    }

    int query(int x1, int y1, int x2, int y2) {
        int k = log2int(x2 - x1 + 1);
        int l = log2int(y2 - y1 + 1);
        return max({
            table[x1][y1][k][l],
            table[x2 - (1 << k) + 1][y1][k][l],
            table[x1][y2 - (1 << l) + 1][k][l],
            table[x2 - (1 << k) + 1][y2 - (1 << l) + 1][k][l]
        });
    }
};
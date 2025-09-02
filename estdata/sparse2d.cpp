const int N = 100;
int matrix[N][N];
int table[N][N][(int)(log2(N) + 1)][(int)(log2(N) + 1)];

void build_sparse_table(int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            table[i][j][0][0] = matrix[i][j];
        }
    }

    for (int k = 1; k <= (int)(log2(n)); k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            for (int j = 0; j + (1 << k) - 1 < m; j++) {
                table[i][j][k][0] = min(
                    table[i][j][k - 1][0],
                    table[i + (1 << (k - 1))][j][k - 1][0]);
            }
        }
    }

    for (int k = 1; k <= (int)(log2(m)); k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + (1 << k) - 1 < m; j++) {
                table[i][j][0][k] = min(
                    table[i][j][0][k - 1],
                    table[i][j + (1 << (k - 1))][0][k - 1]);
            }
        }
    }

    for (int k = 1; k <= (int)(log2(n)); k++) {
        for (int l = 1; l <= (int)(log2(m)); l++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                for (int j = 0; j + (1 << l) - 1 < m; j++) {
                    table[i][j][k][l] = min(
                        min(table[i][j][k - 1][l - 1],
                            table[i + (1 << (k - 1))][j]
                                 [k - 1][l - 1]),
                        min(table[i][j + (1 << (l - 1))]
                                 [k - 1][l - 1],
                            table[i + (1 << (k - 1))]
                                 [j + (1 << (l - 1))][k - 1]
                                 [l - 1]));
                }
            }
        }
    }
}
int f(int a, int b){
    return min(a, b);
}

int rmq(int x1, int y1, int x2, int y2)
{
    int k = log2(x2 - x1 + 1);
    int l = log2(y2 - y1 + 1);

    return f(f(table[x1][y1][k][l],
                   table[x2 - (1 << k) + 1][y1][k][l]),
               f(table[x1][y2 - (1 << l) + 1][k][l],
                   table[x2 - (1 << k) + 1]
                        [y2 - (1 << l) + 1][k][l]));
}
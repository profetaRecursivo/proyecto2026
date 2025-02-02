const int MAXN = 1e6;
const int K = 21 + 1;// deberia de ser el logaritmo de MAXN

int st[K + 1][MAXN];

int f(int a, int b){
    return min(a, b);
}

void initsparse(vector<int>& array, int N){
    std::copy(array.begin(), array.end(), st[0]);
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
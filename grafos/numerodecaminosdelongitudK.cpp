const int MOD = 1e9 + 7; // Usar módulo si se necesita para evitar overflow
// Multiplica dos matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                resultado[i][j] = (resultado[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return resultado;
}
vector<vector<int>> exponenciarMatriz(vector<vector<int>> base, int k) {
    int n = base.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        resultado[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            resultado = multiplicarMatrices(resultado, base);
        }
        base = multiplicarMatrices(base, base);
        k >>= 1;
    }
    return resultado;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> matriz(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    vector<vector<int>> resultado = exponenciarMatriz(matriz, k);

    cout << "Número de caminos de longitud " << k << " entre los vértices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

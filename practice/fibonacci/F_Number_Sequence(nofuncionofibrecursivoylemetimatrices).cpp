#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

// Función para multiplicar dos matrices 2x2 bajo módulo
vector<vector<long long>> matrix_mult(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long mod) {
    return {
        {(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod, (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod},
        {(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod, (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod}
    };
}

// Función para hacer la exponenciación de matrices bajo módulo
vector<vector<long long>> matrix_pow(vector<vector<long long>>& M, long long power, long long mod) {
    vector<vector<long long>> result = {{1, 0}, {0, 1}}; // Matriz identidad
    vector<vector<long long>> base = M;
    
    while (power > 0) {
        if (power % 2 == 1) {
            result = matrix_mult(result, base, mod);
        }
        base = matrix_mult(base, base, mod);
        power /= 2;
    }
    
    return result;
}

// Función para calcular el n-ésimo número de Fibonacci mod 10^m
long long fibonacci_mod(long long n, long long a, long long b, long long m) {
    if (n == 0) return a % m;
    if (n == 1) return b % m;

    vector<vector<long long>> T = {{1, 1}, {1, 0}}; // Matriz de transición
    vector<vector<long long>> Tn_minus_1 = matrix_pow(T, n - 1, m);  // Calcula T^(n-1)

    // f(n) será el producto de T^(n-1) con el vector [b, a]
    long long fn = (Tn_minus_1[0][0] * b + Tn_minus_1[0][1] * a) % m;
    
    return fn;
}
int tc = 1;
void solve() {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;

    // Calcular 10^m
    long long mod = 1;
    for (long long i = 0; i < m; ++i) {
        mod *= 10;  // Calcula 10^m
    }

    cout << "Case "<<tc++<<": "<<fibonacci_mod(n, a, b, mod) << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t; while (t--) solve();
}

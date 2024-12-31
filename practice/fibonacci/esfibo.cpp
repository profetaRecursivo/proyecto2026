#include <bits/stdc++.h>
using namespace std;

bool esCuadradoPerfecto(__int128_t x) {
    if (x < 0) return false;
    __int128_t raiz = sqrt((long double)x);
    return raiz * raiz == x;
}

string isFibo(long long n) {
    __int128_t a = 5;
    a *= n;
    a *= n;
    __int128_t b = a - 4;
    a += 4;
    if (esCuadradoPerfecto(a) || esCuadradoPerfecto(b)) {
        return "IsFibo";
    } else {
        return "IsNotFibo";
    }
}

int main() {
    int t;
    cin >> t; // Número de casos de prueba
    while (t--) {
        long long n;
        cin >> n;
        cout << isFibo(n) << endl;
    }
    return 0;
}

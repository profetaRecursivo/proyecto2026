#include <bits/stdc++.h>
using namespace std;
double f(int x) {
    // Ejemplo: una parábola con máximo en x = 3
    return -(x - 3) * (x - 3) + 10;
}
int main() {
    int l = -10, r = 10; // rango de búsqueda
    while (r - l >= 3) { // mientras quede más de 2 elementos
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    // Buscar el mejor valor entre los últimos candidatos
    double best = f(l);
    int bestX = l;
    for (int i = l + 1; i <= r; i++) {
        double val = f(i);
        if (val > best) best = val, bestX = i;
    }

    cout << "Maximo en x = " << bestX << " con valor " << best << "\n";
}
double f(double x) {
    // Ejemplo: máximo en x = 2.5
    return -(x - 2.5) * (x - 2.5) + 5;
}

int main() {
    double l = -10, r = 10;
    const double eps = 1e-9; // precisión
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    double x = (l + r) / 2;
    cout << fixed << setprecision(10);
    cout << "Maximo en x = " << x << " con valor " << f(x) << "\n";
}

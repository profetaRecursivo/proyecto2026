#include <iostream>
#include <vector>

using namespace std;
#define vi vector<int>

vi applyperm(vi& secuencia, vi& permutacion) {
    vi ans(secuencia.size());
    for (int i = 0; i < secuencia.size(); i++) {
        ans[i] = secuencia[permutacion[i]];
    }
    return ans;
}

vi permutar(vi secuencia, vi permutacion, long long k) {
    while (k > 0) {
        if (k & 1) {
            secuencia = applyperm(secuencia, permutacion);
        }
        permutacion = applyperm(permutacion, permutacion);
        k >>= 1;
    }
    return secuencia;
}
//secuencia = arreglo de los numeros original
//permutacion = arreglo de nuevos indices para aplicar a la secuencia
//complejidad O(nlogk)
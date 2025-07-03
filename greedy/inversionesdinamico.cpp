/*1 x – Insertar x al final de la secuencia.

Después de insertar x, añade al contador total de inversiones la cantidad de elementos anteriores en la secuencia que son mayores que x.

2 i x Actualizar el valor en la posición i a x.

    Se reemplaza el valor que estaba en la posición i (1-indexado) por x.

    Debes actualizar el total de inversiones considerando que el nuevo valor podría generar o eliminar inversiones.

    Si i es inválido (fuera del rango actual), ignora la operación.

3  Imprimir el número total de inversiones actuales en la secuencia.

4 x  Imprimir cuántos elementos actualmente en la secuencia son mayores que x.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fore(i,a,b) for(int i = a; i < b; i++)

vector<ll> bit;
int n;
ll totalInversiones = 0;
vector<ll> arr; // guarda los elementos insertados en orden
unordered_map<int, int> compressedIndex;

void update(int pos, ll delta){
    while (pos <= n) {
        bit[pos] += delta;
        pos += pos & -pos;
    }
}

ll query(int pos){
    ll sum = 0;
    while (pos > 0) {
        sum += bit[pos];
        pos -= pos & -pos;
    }
    return sum;
}

int getIndex(ll x, const vector<ll>& vals) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    vector<tuple<int, ll, ll>> queries; // tipo, arg1, arg2 (solo se usa si aplica)
    vector<ll> allValues; // para compresión

    // Leer todas las queries primero para poder comprimir
    fore(i, 0, q){
        int tipo;
        ll a = 0, b = 0;
        cin >> tipo;
        if (tipo == 1 || tipo == 4) {
            cin >> a;
            allValues.push_back(a);
        } else if (tipo == 2) {
            cin >> a >> b;
            allValues.push_back(b);
        }
        queries.emplace_back(tipo, a, b);
    }

    // Compresión de coordenadas
    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());

    n = allValues.size();
    bit.assign(n + 2, 0);

    auto get = [&](ll x) {
        return lower_bound(allValues.begin(), allValues.end(), x) - allValues.begin() + 1;
    };

    fore(i, 0, q){
        auto [tipo, a, b] = queries[i];

        if (tipo == 1) {
            // Insertar x
            int idx = get(a);
            totalInversiones += query(n) - query(idx);
            update(idx, 1);
            arr.push_back(a);
        } else if (tipo == 2) {
            // Actualizar arr[i] := b
            int i = a - 1; // cuidado con el 0-based
            if (i < 0 || i >= (int)arr.size()) {
                cout << "Índice inválido\n";
                continue;
            }

            int oldIdx = get(arr[i]);
            update(oldIdx, -1); // quitar vieja contribución

            // restar inversiones viejas
            totalInversiones -= query(n) - query(oldIdx);

            arr[i] = b;
            int newIdx = get(b);

            // agregar nueva contribución
            totalInversiones += query(n) - query(newIdx);
            update(newIdx, 1);
        } else if (tipo == 3) {
            // Consultar total de inversiones
            cout << totalInversiones << '\n';
        } else if (tipo == 4) {
            // Cuántos elementos mayores a x
            int idx = get(a);
            ll mayores = query(n) - query(idx);
            cout << mayores << '\n';
        }
    }
}

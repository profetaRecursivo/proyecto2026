#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

struct Sqrt {
    int n;
    int B;
    vector<ll> data;
    vector<ll> lazy;
    vector<vector<ll>> blocks;

    Sqrt(const vector<ll>& arr) {
        n = sz(arr);
        B = sqrt(n);
        data = arr;
        int nblocks = (n + B - 1) / B;
        lazy.assign(nblocks, 0);
        blocks.resize(nblocks);
        for (int b = 0; b < nblocks; b++) { rebuild_block(b); }
    }

    void rebuild_block(int b_idx) {
        blocks[b_idx].clear();
        blocks[b_idx].reserve(B + 1);

        int start = b_idx * B;
        int end = min((b_idx + 1) * B, n);

        for (int i = start; i < end; i++) { blocks[b_idx].push_back(data[i]); }
        sort(all(blocks[b_idx]));
    }

    void update(int l, int r, ll x) {
        int start_block = l / B;
        int end_block = r / B;

        if (start_block == end_block) {
            for (int i = l; i <= r; i++) data[i] += x;
            rebuild_block(start_block);
        } else {
            for (int i = l; i < (start_block + 1) * B; i++) data[i] += x;
            rebuild_block(start_block);

            for (int b = start_block + 1; b < end_block; b++) { lazy[b] += x; }

            for (int i = end_block * B; i <= r; i++) data[i] += x;
            rebuild_block(end_block);
        }
    }

    int count_less_equal(ll val) {
        int count = 0;
        int nblocks = sz(blocks);
        for (int b = 0; b < nblocks; b++) {
            ll target = val - lazy[b];
            auto it = upper_bound(blocks[b].begin(), blocks[b].end(), target);
            count += (it - blocks[b].begin());
        }
        return count;
    }

    ll query_median() {
        ll l = -2e14, r = 2e14;
        ll ans = r;
        int required_count = (n / 2) + 1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (count_less_equal(mid) >= required_count) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Crear el arreglo inicial
    vector<ll> arr = {1, 5, 2, 8, 3};

    // 2. Construir la estructura SQRT
    Sqrt sq(arr);

    // Arreglo actual: [1, 5, 2, 8, 3]
    // Ordenado sería: [1, 2, 3, 5, 8] -> La mediana (3er elemento) es 3
    cout << "Mediana inicial: " << sq.query_median() << "\n"; // Imprime 3

    // 3. Sumar +5 a las posiciones en el rango [0, 2] (índices 0, 1 y 2)
    // El arreglo pasa a ser: [1+5, 5+5, 2+5, 8, 3] = [6, 10, 7, 8, 3]
    sq.update(0, 2, 5);

    // Arreglo actual: [6, 10, 7, 8, 3]
    // Ordenado sería: [3, 6, 7, 8, 10] -> La nueva mediana es 7
    cout << "Mediana tras update: " << sq.query_median() << "\n"; // Imprime 7

    return 0;
}
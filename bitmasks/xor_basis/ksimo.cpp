You are given an empty sequence a
. Your task is to process q
 queries of the following types:

1. Append x
 to the end of sequence a
;

2. Among all distinct numbers you can produce by choosing any subsequence(possibly empty) from a
 and calculating their bitwise XOR, print the k
-th smallest one. If such a number does not exist, print −1
 instead.

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll  = long long;

vector<ull> B;

void insertBasis(ull x) {
    // Reducir contra la base actual
    for (ull b : B) 
        x = min(x, x ^ b);
    if (!x) return;  // ya dependiente

    // Limpiar los anteriores con el nuevo
    for (ull &b : B) 
        b = min(b, b ^ x);

    B.push_back(x);
    sort(B.begin(), B.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int t; ull x;
        cin >> t >> x;
        if (t == 1) {
            insertBasis(x);
        } else {
            ull k = x;
            // Total de combinaciones = 2^|B|
            if (k > (1ULL << B.size())) {
                cout << "-1\n";
                continue;
            }
            // convertir a 0-based
            k--;
            ull res = 0;
            for (int i = 0; i < (int)B.size(); i++) {
                if (k & (1ULL << i))
                    res ^= B[i];
            }
            cout << res << "\n";
        }
    }
    return 0;
}
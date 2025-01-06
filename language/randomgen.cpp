#include <bits/stdc++.h>
using namespace std;

void generateRandomNumbers(int n, int l, int r) {
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(l, r);
    for (int i = 0; i < n; ++i) {
        cout << distrib(gen) << "\n";
    }
    cout << endl;
}

int main() {
    int n, l, r;
    cin >> n;
    cin >> l >> r;

    if (l > r || n <= 0) {
        cerr << "Entrada invalida." << endl;
        return 1;
    }

    generateRandomNumbers(n, l, r);
    return 0;
}

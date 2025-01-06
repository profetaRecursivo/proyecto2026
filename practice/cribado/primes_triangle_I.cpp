#include <bits/stdc++.h>
using namespace std;

vector<int> primos;

void solve(int n) {
    const int S = 100000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    
    vector<char> esprimo(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (esprimo[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i) {
                esprimo[j] = false;
            }
        }
    }

    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        
        int start = k * S;
        
        for (int p : primes) {
            int posini = max(p * p, (start + p - 1) / p * p);
            for (int j = posini - start; j < S; j += p) {
                block[j] = false;
            }
        }

        if (k == 0) block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]) primos.push_back(start + i);
        }
    }
}

const int con = 10790;
#define ll long long
ll calcserie(ll n) {
    return (n * (n + 1)) / 2;
}

void solve() {
    int x;
    cin >> x;
    int idx = -1;
    int l = 0, r = primos.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (primos[mid] == x) {
            idx = mid + 1;
            break;
        } else if (primos[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (idx == -1) {
        cout << "-1\n";
    } else {
        l = 0, r = con - 1;
        int pos;
        bool ok = false;
        while (l <= r) {
            int mid = (l + r) / 2;
            const int u = calcserie(mid);
            if (u == idx) {
                pos = mid;
                ok = true;
                break;
            } else if (u < idx) {
                l = mid + 1;
            } else {
                pos = mid;
                r = mid - 1;
            }
        }
        if (pos == 0) {
            cout << "1 1\n";
        } else {
            printf("%d %d\n", pos, idx - calcserie(pos - 1));
        }
    }
}

int main() {
    solve(100000007); // Generar los primos hasta 10^8
    int t = 1;
    cin >> t;
    while (t--) solve();
}

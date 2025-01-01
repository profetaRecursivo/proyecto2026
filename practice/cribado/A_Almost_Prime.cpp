#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
vector<int> divprimos(N + 1, 0);

void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (divprimos[i] == 0) { 
            for (int j = i; j <= N; j += i) {
                divprimos[j]++;
            }
        }
    }
}

signed main() {
    sieve();
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (divprimos[i] == 2) {
            ans++;
        }
    }
    cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    const int S = 10000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> esprimo(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (esprimo[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                esprimo[j] = false;
        }
    }
    vector<int> primos;
    vector<char> block(S);

    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int posini = (start + p - 1) / p;
            for (int j = max(posini, p) * p - start; j < S; j += p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;

        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                primos.push_back(start + i);
        }
    }
    for (int i = 0; i < (int)primos.size(); i += 100) {
        printf("%d\n", primos[i]);
    }
}

signed main() {
    int n = 100000000;
    solve(n);
    return 0;
}

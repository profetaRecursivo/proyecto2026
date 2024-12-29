#include "bits/stdc++.h"
using namespace std;
#define vvi vector<vector<int>>

vvi multiply(const vvi& A, const vvi& B) {
    vvi ans(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ans;
}

vvi matrixPower(vvi base, int n) {
    vvi ans = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n&1) {
            ans = multiply(ans, base);
        }
        base = multiply(base, base);
        n>>=1;
    }
    return ans;
}
//Driver code:
int fibo(int n) {
    if (n == 0) return 0;
    vvi transition = {{1, 1}, {1, 0}};
    vvi ans = matrixPower(transition, n - 1);
    return ans[0][0];
}
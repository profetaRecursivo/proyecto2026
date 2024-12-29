#include <bits/stdc++.h>
using namespace std;
const int MOD = 10000007;
#define int long long
/*mas que binpow, era matematico
zn + zn-1 - 2*zn-2 puedes calcularlo de manera 
matematicca, descartando terminos inutiles*/
//PLUS ULTRA RECARGADO!!!
int expmod(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    while(1){
        cin>>n>>k;
        if(n == 0 and k == 0)break;
        int ans = expmod(n, n, MOD) + 2 * expmod(n-1, n-1, MOD);
        ans%=MOD;
        ans+=expmod(n, k, MOD) + 2*expmod(n-1, k, MOD);
        ans%=MOD;
        cout<<ans<<endl;
    }
}
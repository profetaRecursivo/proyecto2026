#include <bits/stdc++.h>
using namespace std;
#define int long long
const int tam = 1e6;

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
int phi(int n) {
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}
void solve(){
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);
    int n, mod;cin>>n>>mod;
    if(n == 0){
        cout<<(3%mod)<<endl;
        return;
    }
    int base = 2LL;
    int fi = phi(mod);
    int exponente = fi + expmod(2LL, n, fi);
    int ans = expmod(base, exponente, mod) + 1;
    ans%=mod;
    cout<<ans<<endl;
}
signed main(){
    solve();
}
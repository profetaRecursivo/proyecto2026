#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1000009;
ll fact[tam], invFact[tam];
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void prec() {
    fact[0] = 1;
    for (int i = 1; i < tam; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[tam - 1] = expmod(fact[tam - 1], MOD - 2, MOD);
    for (int i = tam - 2; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}
ll nck(ll n, ll k){
    return fact[n] * invFact[k] %MOD * invFact[n-k] %MOD;
}
void solve(){
    int n, k;cin>>n>>k;
    cout<<nck(n, k)<<endl;
}

signed main(){
    prec();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
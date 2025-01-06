#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18;
#define ll long long
#define sz(x) (int)(x).size()
//si isPrime[i] = true, entonces el numero L + i es primo
vector<char> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
void solve(){
    ll l, r;cin>>l>>r;
    vector<char> seg = segmentedSieve(l , r);
    for(int i = 0; i<sz(seg); i++){
        if(seg[i] == true){
            cout<<l+i<<'\n';
        }
    }
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
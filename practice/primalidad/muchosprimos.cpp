// Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

// Input
// The input begins with the number t of test cases in a single line (t ≤ 10). In each of the next t lines there are two numbers m and n (1 ≤ m ≤ n ≤ 1000000000, n-m ≤ 100000) separated by a space.

// Output
// For every test case print all prime numbers p such that m ≤ p ≤ n, one number per line, test cases separated by an empty line.
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
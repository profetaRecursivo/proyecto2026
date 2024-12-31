#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
int n;
vector<bool> is_prime(n+1, true);
vector<int> primos
void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
void solve(){

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
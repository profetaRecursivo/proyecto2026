#include "bits/stdc++.h"
using namespace std;
#define int long long
int TC = 1;
void solve(){
    int a, b, c;cin>>a>>b>>c;
    bool ok = c%__gcd(a, b) == 0;
    cout<<"Case "<<TC++<<": "<<(ok?"Yes\n":"No\n");
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}


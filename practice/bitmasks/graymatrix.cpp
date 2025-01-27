#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
using namespace std;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
//Now that dont kill me, can only make me stronger.
vector<int> gray(int n){
    n = 1<<n;
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        ans[i] = i^(i>>1);
    }
    rotate(ans.begin(), ans.begin() + 1, ans.end());
    return ans;
}
void solve(){
    int n, m;cin>>n>>m;
    auto a = gray(n);
    auto b = gray(m);     
    for(int i = 0; i<(1<<n); i++){
        for(int j = 0; j<(1<<m); j++){
            cout<<(a[i]^(b[j]<<n))<<' ';
        }
        cout<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
   //cin>>t;
    while(t--)solve();
}
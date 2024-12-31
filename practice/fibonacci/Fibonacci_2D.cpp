#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int INF = 1e18;
const int MOD = 1e9+7;
//f(x, y) = f(x-1, y) + f(x, y-1) + f(x-1,y-1)
//base f(x, 0) = f(y, 0) = 1
int dp[1003][1003];
void init(){
    memset(dp, 0, sizeof dp);
    for(int i = 0; i<1003; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for(int i = 1; i<1003; i++){
        for(int j = 1; j<1003; j++){
            dp[i][j] = ((dp[i-1][j] + dp[i][j-1])%MOD + dp[i-1][j-1])%MOD;
        }
    }
}    
void solve(){
    int x, y;cin>>x>>y;
    cout<<dp[x][y]<<endl;
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
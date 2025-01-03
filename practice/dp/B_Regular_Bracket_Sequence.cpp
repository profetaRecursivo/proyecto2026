#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
#define sz(x) (int)(x).size();
int memo[1000050];
int n;
string s;

int dp(int i, int balance, int metidos){
    if(i == n){
        return metidos;
    }else{
        if(memo[i] == -1){
            int tomar = 0, notomar = 0;
            if (s[i] == '(')
                tomar = dp(i + 1, balance + 1, metidos);
            else if (balance > 0) {
                tomar = dp(i + 1, balance - 1, metidos + 2); 
            }
            notomar = dp(i + 1, balance, metidos);
            memo[i] = max(tomar, notomar);
        }
        return memo[i];
    }
}

void solve(){
    memset(memo, -1, sizeof memo);
    cin >> s;
    n = sz(s);
    cout << dp(0, 0, 0) << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--) solve();
}

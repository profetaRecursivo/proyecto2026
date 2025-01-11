#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
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

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x;
    while(1){
        cin>>x;if(x == 0)break;
        if(x == 1){
            cout<<0<<endl;
            continue;
        }
        cout<<phi(x)<<endl;
    }
}
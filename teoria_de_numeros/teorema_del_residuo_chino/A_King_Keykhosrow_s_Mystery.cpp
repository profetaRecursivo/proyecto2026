#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
int gecd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm (int a, int b) {
    return a / gecd(a, b) * b;
}
void solve(){
    int a, b;cin>>a>>b;
    ll l = lcm(a, b);
    if(l >= a or l>=b){
        cout<<l<<endl;
    }else{
        l*=max(a, b);
        cout<<l<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}
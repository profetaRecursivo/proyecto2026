#include "bits/stdc++.h"
#define int long long
#define ld long double
using namespace std;
int expmod(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
#define sz(x) (x).size()
string f(int x){
    string ans = to_string(x);
    while(sz(ans) < 3)ans = '0' + ans;
    return ans;
}
const ld EPS = 1e-9;
void solve(){
    int n, k;cin>>n>>k;
    int tras = expmod(n, k, 1000);
    string trass = f(tras);
    //despejamos log x^y = y*log x
    ld delante = (ld)k*log10l(n);
    delante-=floorl(delante) - 2;
    delante = powl(10.0, delante);
    cout<<floorl(delante + EPS)<<"..."<<trass<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
}
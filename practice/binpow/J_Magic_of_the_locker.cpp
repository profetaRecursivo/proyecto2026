#include "bits/stdc++.h"
using namespace std;
#define int long long
/*
dado n maximizar el producto x*y*z*...k 
tal que x+y+z+...+k = n
Se consigue con un formulazo 
y un analisis basandose en la constante
de euler
2 y 3 cercanos a euler
*/
int mulmod(int a, int b, int m) {
    int ans = 0; 
    while (a > 0) {
        if (a&1) {
            ans = (ans + b) % m;
        }
        b = (b<<1) % m;
        a>>=1;
    }
    return ans; 
}
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
const int MOD = 1e9+7;
void solve(){
    int x;cin>>x;
    if(x == 1){
        cout<<1<<endl;
        return;
    }
    int q = x/3;
    int r = x%3;
    if(r == 0){
        cout<<expmod(3,q,MOD)%MOD;
    }else if(r == 1){
        cout<<mulmod(4, expmod(3, q-1, MOD), MOD)%MOD;
    }else{
        cout<<mulmod(2, expmod(3, q, MOD), MOD)%MOD;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){solve();if(t)cout<<'\n';}
}
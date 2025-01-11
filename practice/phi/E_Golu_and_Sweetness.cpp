#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e18;
// const int tam = 1e7;

// vector<int> phi(tam + 1);
// void euler() {
// 	for (int i = 0; i <= tam; i++) phi[i] = i;
// 	for (int i = 2; i <= tam; i++) {
// 		if (phi[i] == i) {
// 			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
// 		}
// 	}
// }
// int fi(ll n) {
//     ll ans = n;
//     for (ll i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             while (n % i == 0)
//                 n /= i;
//             ans -= ans / i;
//         }
//     }
//     if (n > 1)
//         ans -= ans / n;
//     return ans;
// }
// void init(){
//     euler();
// }
// void test(){
//     for(ll i = 1; i<(ll)tam *2; i++){
//         if(fi(i) == 2)cout<<i<<' ';
//     }
// }
void solve(){
    int n, q;cin>>n>>q;
    int arr[n+1];
    arr[0] = 0;
    for(int i = 1; i<=n; i++){
        ll x;cin>>x;
        arr[i] = x == 3 or x == 4 or x == 6;
    }
    for(int i = 1; i<=n; i++){
        arr[i]+=arr[i-1];
    }
    while(q--){
        int l, r;cin>>l>>r;
        cout<<arr[r] - arr[l-1]<<endl; 
    }
}
signed main(){
  //  init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)solve();
}

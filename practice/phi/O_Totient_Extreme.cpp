#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const int tam = 1e4 + 50;
vector<int> phi(tam + 1);
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
vector<int> ans(tam+1);
void init(){
    euler();
    for(int i = 1; i<=tam; i++){
        ans[i]+=ans[i-1] + phi[i];
    }
}
void solve(){
    int n;cin>>n;
    cout<<((ull)ans[n])*((ull)ans[n])<<'\n';
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}
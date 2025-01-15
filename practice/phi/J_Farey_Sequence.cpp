#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const int tam = 1000050;
vector<int> phi(tam + 1);
void euler() {
	for (int i = 0; i <= tam; i++) phi[i] = i;
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
vector<ll> ans(tam+1);
void init(){
    for(int i = 1; i<=tam; i++){
        ans[i] = ans[i-1] + phi[i];
    }
} 
void solve(int x){
    cout<<ans[x]-1<<endl;
}
signed main(){
	euler();
    init();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(1){
        int x;cin>>x;
        if(x == 0)break;
        solve(x);
    }
}
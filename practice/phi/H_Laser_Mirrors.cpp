#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const int tam = 100050;
vector<int> phi(tam + 1);
void euler() {
	for (int i = 0; i <= tam; i++) phi[i] = i;
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
void solve(){
	int x;cin>>x;
	cout<<phi[x]<<'\n';
}
signed main(){
	euler();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--)solve();
}
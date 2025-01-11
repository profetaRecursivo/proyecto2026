#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e6 + 10;
vector<int> phi(N + 1);
void euler() {
	for (int i = 0; i <= N; i++) phi[i] = i;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) phi[j] -= phi[j] / i;
		}
	}
}

void solve(){
    int x;cin>>x;
    cout<<phi[x]<<endl;
}
signed main(){
    euler();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
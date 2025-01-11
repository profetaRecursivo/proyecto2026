#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int tam = 2000050;
vector<int> phi(tam + 1);
int arr[tam+1];
int prefix[tam+1];

void euler() {
	for (int i = 0; i <= tam; i++) phi[i] = i;
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
void init(){
    euler();
    memset(prefix, 0, sizeof prefix);
    memset(arr, -1, sizeof arr);
    arr[0] = 0;
    for(int i = 1; i<=tam; i++){
        int x = i;
        int aux = 0;
        while(x != 1){
            x = phi[x];
            aux++;
        }
        arr[i] = aux;
    }
    for(int i = 1; i<=tam; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
}
void solve(){
    int l, r;cin>>l>>r;
    cout<<prefix[r] - prefix[l-1]<<'\n';
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;while(t--)solve();
}
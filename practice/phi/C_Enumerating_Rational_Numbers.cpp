#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll tam = 500000;
vector<ll> phi(tam + 1);
vector<ll> prefix(tam+1);
void euler() {
	for (ll i = 0; i <= tam; i++) phi[i] = i;
	for (ll i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (ll j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
    for(ll i = 1; i<=tam; i++){
        prefix[i] = prefix[i-1] + phi[i];
    }
}

ll gecd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
void solve(ll x){
    if(x == 1){
        cout<<"0/1"<<endl;
        return;
    }
    x--;
    auto it = lower_bound(prefix.begin(), prefix.end(), x);
    ll pos = it - prefix.begin();
    //ahora que tengo su pos necesito ese numero
    ll cant = x -  prefix[pos-1] + 1;
    ll den = pos;
    ll i =1;
    while(cant > 1){
        ll g = gecd(i, den);
        if(g == 1){
            cant--;
        }
        i++;
    }
    cout<<i-1<<"/"<<den<<endl;
}
signed main(){
    euler();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    while(1){
        cin>>n;
        if(n == 0)break;
        solve(n);
    }
}
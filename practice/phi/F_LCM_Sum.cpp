#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int tam = 1000000;

vector<int> phi(tam + 1);
vector<ll> ans(tam + 1);
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}

void init() {
	euler();
	for (int i = 1; i <= tam; i++) {
		for (int j = i; j <= tam; j += i) { ans[j] += ((ll)i * phi[i]); }
	}
}
void solve() {
	int x;
	scanf("%d", &x);
	ll res = ans[x];
	res = (res + 1) * x;
	printf("%lld\n", res/2);
}
signed main() {
	int t = 1;
	scanf("%d", &t);
	init();
	while (t--) solve();
}
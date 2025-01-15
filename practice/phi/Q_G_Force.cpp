#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const int tam = 1e7 + 10;
vector<int> phi(tam + 1);
int expmod(int a, int b, int m) {
	a %= m;
	int res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
vector<int> spf(tam + 1);
vector<int> prim;
void sieve() {
	for (int i = 2; i <= tam; ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			prim.push_back(i);
		}
		for (int j = 0; i * prim[j] <= tam; ++j) {
			spf[i * prim[j]] = prim[j];
			if (prim[j] == spf[i]) { break; }
		}
	}
}
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
vector<int> f(tam + 1);
vector<ll> g(tam + 1);
void init() {
	euler();
	sieve();
	int acum = 0;
	for (int i = 1; i <= tam; i++) {
		acum = acum + (spf[i] == i);
		f[i] = max(0, acum - phi[i]);
	}
	for (int i = 1; i <= tam; i++) {
		g[i] = (f[i] == 0 or f[i] == 1 ? (phi[i]) : (phi[i] * phi[i]));
	}
}
void solve() {
	int x;
	cin >> x;
	cout << g[x] << endl;
}
signed main() {
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
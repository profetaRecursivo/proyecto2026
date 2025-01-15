#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const int tam = 5 * 1e6 + 50;
vector<int> phi(tam + 1);
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
vector<ull> ans(tam + 1);
void init() {
	euler();
	for (int i = 1; i <= tam; i++) {
		ans[i] = ans[i - 1] + (ull)phi[i] * phi[i];
	}
}

int tc = 1;
void solve() {
	int l, r;
	cin >> l >> r;
	ull res = ans[r] - ans[l - 1];
	cout << "Case " << tc++ << ": " << res << '\n';
}
signed main() {
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = __amd64;
	cin >> t;
	while (t--) solve();
}
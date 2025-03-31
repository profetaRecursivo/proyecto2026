
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 31;
ll C[tam + 1][tam + 1];
void prec() {
	memset(C, 0, sizeof C);
	C[0][0] = 1;
	for (int n = 1; n <= tam; ++n) {
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k) C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}
}
void solve() {
	int x, y, n;
	cin >> x >> y >> n;
	ll ans = 0;
	for (int i = 4; i < n; i++) {
		if (x < i or y < n - i) continue;
		ans += (C[x][i] * C[y][n - i]);
	}
	cout << ans << endl;
}

signed main() {
	prec();
	// cout<<C[4][5]<<endl;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}
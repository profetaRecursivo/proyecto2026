#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1000030;
#define sz(x) (int)(x).size()
vector<int> spf(N + 1);
vector<int> prim;
int g(int x) {
    set<int> factors;
    while (x > 1) {
        factors.insert(spf[x]);
        x /= spf[x];
    }
    return sz(factors);
}
void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (spf[i] == 0) {
			spf[i] = i;
			prim.push_back(i);
		}
		for (int j = 0; i * prim[j] <= N; ++j) {
			spf[i * prim[j]] = prim[j];
			if (prim[j] == spf[i]) { break; }
		}
	}
}
vector<int> f(N + 1);
vector<vector<int>> prefijos(11, vector<int>(N + 1, 0));
void pre() {
	sieve();
	f[1] = 0;
	for (int i = 2; i < N; i++) { f[i] = g(i); }
	for (int i = 0; i <= 10; i++) {
		for (int j = 1; j < N; j++) {
			prefijos[i][j] = prefijos[i][j - 1] + (f[j] == i);
		}
	}
}
void solve() {
	int a, b, n;
	cin >> a >> b >> n;
    cout<<prefijos[n][b] - prefijos[n][a-1]<<endl;;
}
signed main() {
	pre();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
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
const int tam = 2000;
ll C[tam + 1][tam + 1];
const ll mod = 1000000000;
void prec() {
	C[0][0] = 1;
	for (int n = 1; n <= tam; ++n) {
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k) C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%mod;
	}
}
void solve() {
	int k, n;
	cin >> k >> n;
    cout<<C[n+k-1][k-1]<<endl;
}

signed main() {
    prec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) { solve(); }
}
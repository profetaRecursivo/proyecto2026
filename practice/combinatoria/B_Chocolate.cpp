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
const int tam = 1;

void solve() {
	ll ans = 1;
	int n;
	cin >> n;
	vi we;
	fore(i, 0, n) {
		int x;
		cin >> x;
		if (x) we.pb(i);
	}
	if (sz(we) == 0) {
		cout << 0 << endl;
	} else {
		for (int i = 1; i < sz(we); ++i) { ans *= (we[i] - we[i - 1]); }
		cout << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin>>t;
	while (t--) { solve(); }
}
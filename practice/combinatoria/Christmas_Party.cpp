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
const int tam = 1000000 + 10;

ll des[tam];

void precdes() {
	des[0] = 1;
	des[1] = 0;	
	for (int i = 2; i < tam; ++i) {
		des[i] = (i - 1) * ((des[i - 1] + des[i - 2]) % MOD) % MOD;
	}
}

void solve() {
	int n;
	cin >> n;
	cout << des[n] << endl;
}

signed main() {
	precdes();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}

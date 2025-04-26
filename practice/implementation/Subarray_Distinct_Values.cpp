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
ll g(ll tam) { return tam * (tam + 1) / 2; }
void solve() {
	int n, k;
	cin >> n >> k;
	vi arr(n);
	fore(i, 0, n) cin >> arr[i];

	map<int, int> freq;
	int l = 0;
	ll ans = 0;

	fore(r, 0, n) {
		freq[arr[r]]++;
		while (sz(freq) > k) {
			freq[arr[l]]--;
			if (freq[arr[l]] == 0) freq.erase(arr[l]);
			l++;
		}
		ans += (r - l + 1);
	}
	cout << ans << '\n';
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//   cin>>t;
	while (t--) { solve(); }
}
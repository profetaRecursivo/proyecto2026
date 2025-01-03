#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18;

const int N = 1e6 * 2;
vector<int> lp(N + 1);
vector<int> pr;
void lsieve() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) { break; }
		}
	}
}
int f(int x) {
	int ans = 0;
	while (x > 1) {
		ans++;
		x /= lp[x];
	}
	return ans;
}
vector<pair<int, int>> arr(N + 1);
void pre() {
	arr[0] = {0, 0};
	arr[1] = {0, 1};
	for (int i = 2; i <= N; i++) { arr[i] = {f(i), i}; }
	sort(arr.begin(), arr.end());

	// ans[1] = 1;
	// for (int i = 2; i <= N; i++) { ans[arr[i].second] = i; }
}
int tc = 1;
void solve(int x) { cout << "Case " << tc++ << ": " << arr[x].second << '\n'; }
signed main() {
	lsieve();
	//cout << f(35) << "pe " << f(20) << "\n";
	pre();
	int x;
	while (1) {
		cin >> x;
		if (x == 0) break;
		solve(x);
	}
}
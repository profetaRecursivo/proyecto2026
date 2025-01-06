#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int INF = 1e18;

const int N = 1000050;
vector<int> spf(N + 1);
vector<int> prim;

void sieve() {
	spf[0] = spf[1] = INF;
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
bool tienecero(int x) {
	string s = to_string(x);
	bool ok = 0;
	for (const char& c : s) { ok |= (c == '0'); }
	return ok;
}

bool asusta(int x) {
	int len = (int)(log10(x) + 1);
	bool ok = 1;
	int fact = 10;
	if (tienecero(x)) return false;
	for (int i = 0; i < len; i++) {
		int num = x % fact;
		// cout<<num<<endl;
		ok &= (spf[num] == num);
		fact *= 10;
	}

	return ok;
}
vector<int> chamo;
void init() {
	sieve();
	for (int i : prim) {
		if (asusta(i)) chamo.push_back(i);
	}
}
void solve() {
	int x;
	scanf("%d", &x);
	int ans;
	bool ok = 0;
	int l = 0, r = (int)chamo.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (chamo[mid] == x) {
			ans = mid;
			ok = 1;
			break;
		} else if (chamo[mid] < x) {
			ans = mid;
			ok = 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	if (ok)
		printf("%d\n", ans + 1);
	else
		printf("%d\n", 0);
}
signed main() {
	init();
	int t = 1;
	scanf("%d", &t);
	// asusta(16586);
	while (t--) { solve(); }
	// cout<<fixed<<setprecision(1)<<(100000.0 * log2l(tam))<<endl;
	//  cout<<f(4632647)<<endl;
}
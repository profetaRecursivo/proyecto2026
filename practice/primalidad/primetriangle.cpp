// The primes triangle is a triangle that contain all prime numbers .

//           2
//         3   5
//       7  11  13
//     17 19  23  29
//   ...
// Your task is very easy given an integer from 1 to 108 print its place in the primes triangle.
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

vector<int> primos;
void solve(int n) {
	const int S = 10000;
	vector<int> primes;
	int nsqrt = sqrt(n);
	vector<char> esprimo(nsqrt + 2, true);
	for (int i = 2; i <= nsqrt; i++) {
		if (esprimo[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= nsqrt; j += i) esprimo[j] = false;
		}
	}
	vector<char> block(S);

	for (int k = 0; k * S <= n; k++) {
		fill(block.begin(), block.end(), true);
		int start = k * S;
		for (int p : primes) {
			int posini = (start + p - 1) / p;
			for (int j = max(posini, p) * p - start; j < S; j += p)
				block[j] = false;
		}

		if (k == 0) block[0] = block[1] = false;

		for (int i = 0; i < S && start + i <= n; i++) {
			if (block[i]) primos.push_back(start + i);
		}
	}
}
const int con = 10790;
#define ll long long
ll calcserie(ll n) {
    return (n * (n + 1)) / 2;
}

void solve() {
	int x;
	cin >> x;
	int idx = -1;
	int l = 0, r = sz(primos) - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (primos[mid] == x) {
			idx = mid + 1;
			break;
		} else if (primos[mid] < x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (idx == -1) {
		puts("-1\n");
	} else {
		// en donde esta?]
		l = 0, r = con - 1;
		int pos;
		bool ok = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
            const int u = calcserie(mid);
			if (u == idx) {
				pos = mid;
				ok = 1;
				break;
			} else if (u < idx) {
				l = mid + 1;
			} else {
				pos = mid;
				r = mid - 1;
			}
		}
		if (pos == 0) {
            puts("1 1\n");
		} else {
            printf("%d %d\n", pos, idx - calcserie(pos-1));
		}
	}
}
signed main() {
    solve(100000007);
	// cout<<sz(primos)<<endl;
	int t = 1;
	scanf("%d", &t);
	while (t--) solve();
}
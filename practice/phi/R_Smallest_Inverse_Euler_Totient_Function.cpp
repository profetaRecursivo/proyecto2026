#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int INF = INT32_MAX;
const int tam = 202918036;
vector<int> phi(tam + 1);
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
int arr[tam + 1];
void init() {
	euler();
	for (int i = 1; i <= tam; i++) { arr[i] = INF; }
	for (int i = 1; i <= tam; i++) { arr[phi[i]] = min(arr[phi[i]], i); }
}

signed main() {
	init();
	int t = 1;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		int ans = arr[x] == INF ? -1 : arr[x];
        printf("%d\n", ans);
	}
}
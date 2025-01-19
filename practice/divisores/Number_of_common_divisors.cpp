#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll INF = 1e18;

int divisores(int n) {
	int ans = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
            ans++;
			if (i != n / i) { ans++; }
		}
	}
	return ans;
}

void solve(){
    int a, b;scanf("%d %d", &a, &b);
    int g = __gcd(a, b);
    printf("%d\n", divisores(g));
}
signed main(){
    int t = 1;
    scanf("%d", &t
    );
    while(t--)solve();
}
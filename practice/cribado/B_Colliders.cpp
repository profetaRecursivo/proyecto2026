#include <bits/stdc++.h>
using namespace std;
const int INF = 1e18;

const int N  = 100009;
vector<int> spf(N + 1);
vector<int> prim;
void sieve()
{
    for (int i = 2; i <= N; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            prim.push_back(i);
        }
        for (int j = 0; i * prim[j] <= N; ++j)
        {
            spf[i * prim[j]] = prim[j];
            if (prim[j] == spf[i])
            {
                break;
            }
        }
    }
}

vector<int> factorizar(int x) {
    vector<int> factors;
    while (x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

map<int, int> fact;
void solve() {
	int n, q;
	cin >> n >> q;
	bool arr[n + 1];
	memset(arr, false, sizeof arr);
	while (q--) {
		char c;
		int x;
		cin >> c >> x;
		auto factores = factorizar(x);
		if (c == '+') {
			if (arr[x]) {
				cout << "Already on\n";
			} else {
				bool ok = 1;
                int conflicto;
				for (int& i : factores) {
                     ok &= (fact[i] == 0); 
                    if(fact[i]!=0){
                        conflicto = fact[i];
                    }
                }
				if (ok) {
					arr[x] = 1;
					for (int& i : factores) { fact[i] = x; }
					cout << "Success\n";
				} else {
					cout << "Conflict with " << conflicto << '\n';
				}
			}
		} else {
			if (arr[x]) {
				for (int& i : factores) { fact[i] = 0; }
                arr[x] = 0;
                cout<<"Success\n";
			}else{
                cout<<"Already off\n";
            }
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    sieve();
	int t = 1;
	// cin>>t;
	while (t--) solve();
}
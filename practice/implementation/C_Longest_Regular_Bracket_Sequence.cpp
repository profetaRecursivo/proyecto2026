#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;

bool conte(int l, int r, set<pair<int, int>>& segm) {
	auto it = segm.upper_bound({l, 0});
	if (it == segm.begin()) return false;
	return (--it)->first < l and it->second > r;
}
void trasquilar(set<pair<int, int>>& seg) {
	vector<pair<int, int>> copia;
	for (auto [l, r] : seg) { copia.push_back({l, r}); }
	for (auto [l, r] : copia) {
		if (conte(l, r, seg)) { seg.erase({l, r}); }
	}
}
vector<pair<int, int>> comprimir(vector<pair<int, int>>& seg) {
	int n = sz(seg);
	sort(all(seg));
	stack<pair<int, int>> casi;
	casi.push(seg[0]);
	fore(i, 1, n) {
		auto [lant, rant] = casi.top();
		auto [lact, ract] = seg[i];
		if (lact == rant + 1) {
			casi.pop();
			casi.push({lant, ract});
		} else {
			casi.push({lact, ract});
		}
	}
	vector<pair<int, int>> ans;
	while (!casi.empty()) {
		ans.push_back(casi.top());
		casi.pop();
	}
	reverse(all(ans));
	return ans;
}
bool coincide(char a, char b) { return a == '(' and b == ')'; }
void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	vi arr(n);
	set<pair<int, int>> segmentos;
	stack<pair<char, int>> pila;
	pila.push({s[0], 0});
	fore(i, 1, n) {
		if (!pila.empty() and coincide(pila.top().first, s[i])) {
			segmentos.insert({pila.top().second, i});
			pila.pop();
		} else {
			pila.push({s[i], i});
		}
	}

	if (!segmentos.empty()) {
		trasquilar(segmentos);
		vector<pair<int, int>> ahorasi;
		for (auto& x : segmentos) { ahorasi.push_back(x); }
        ahorasi = comprimir(ahorasi);
        int maxi = 0;
        map<int, int> frec;
        fore(i, 0, sz(ahorasi)){
            auto[l, r] = ahorasi[i];
            int act = r - l + 1;
            frec[act]++;
            maxi = max(maxi, act);
        }
        cout<<maxi<<' '<<frec[maxi]<<'\n';
	} else {
		cout << "0 1\n";
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
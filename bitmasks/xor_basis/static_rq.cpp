const int tam = 100005;
const int sz = 60;
int n;
int arr[tam];
vector<vector<pair<int, int>>> basis(tam, vector<pair<int, int>>(sz, {0, -1}));
// vector lineal y su posicion
map<int, vector<tuple<int, int, int>>> queries;
int ans[5 * tam + 10];

void insert(int elem, vector<pair<int, int>>& base, int pos) {
	// ahora vot insertando y mejorando la posicion
	for (int i = sz - 1; i >= 0; i--) {
		//
		if (elem & (1LL << i)) {
			if (base[i].first == 0) {
				base[i].first = elem, base[i].second = pos;
				return;
			}
			if (pos < base[i].second) {
				swap(pos, base[i].second);
				swap(elem, base[i].first);
			}
			elem ^= base[i].first;
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		queries[l-1].push_back({r-1, x, i});
	}
	for (int i = n - 1; i >= 0; i--) {
		// construyo la base
		basis[i] = basis[i + 1];
		insert(arr[i], basis[i], i);
		// la base esta consistente, ahora a reducir
		for (auto [r, x, idx] : queries[i]) {
			int val = x;
			for (int b = sz - 1; b >= 0; b--) {
				if (basis[i][b].second > r) continue;
				if (val & (1LL << b)) { val ^= basis[i][b].first; }
			}
			ans[idx] = (val == 0);
		}
	}
	for (int i = 0; i < q; i++) { cout << (ans[i] ? "Yes\n" : "No\n"); }
}
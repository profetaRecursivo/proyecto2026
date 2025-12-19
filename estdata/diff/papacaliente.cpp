void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> xs;
	vector<tuple<int, int, int>> up(n);
	for (int i = 0; i < n; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		up[i] = {l, r, x};
		xs.push_back(l);
		xs.push_back(l + 1);
		xs.push_back(l - 1);
		xs.push_back(r);
		xs.push_back(r + 1);
		xs.push_back(r - 1);
	}
	vector<pair<int, int>> queries(q);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		xs.push_back(l);
		xs.push_back(l + 1);
		xs.push_back(l - 1);
		xs.push_back(r);
		xs.push_back(r + 1);
		xs.push_back(r - 1);
		queries[i] = {l, r};
	}
	sort(all(xs));
	xs.erase(unique(all(xs)), xs.end());
	unordered_map<int, int> idx;
	idx.reserve(sz(xs));
	for (int i = 1; i <= sz(xs); i++) { idx[xs[i - 1]] = i; }
	int m = sz(xs);
	vector<int> diff(m + 2);
	for (auto [l, r, x] : up) {
		diff[idx[l]] += x;
		diff[idx[r + 1]] -= x;
	}
	vector<int> pref(m + 2);
	int p = 0;
	for (int i = 1; i < m; i++) {
		p += diff[i];
		int len = xs[i] - xs[i - 1];
		pref[i] = pref[i - 1] + p * len;
	}
	for (auto [l, r] : queries) {
		cout << pref[idx[r]] - pref[idx[l - 1]] << '\n';
	}
}
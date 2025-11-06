// El indice del segemento redundante, si lo quitas, no se cambia el tiempo de cobertura
map<int, int> v;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> tmp(n);
	vector<int> coords;
	fore(i, 0, n) {
		int x, y;
		cin >> x >> y;
		tmp[i] = {x, y};
		coords.push_back(x);
		coords.push_back(y);
		coords.push_back(x - 1);
		coords.push_back(y + 1);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < sz(coords); i++) { v[coords[i]] = i; }
	vector<int> pt(sz(coords) + 5);
	for (auto p : tmp) {
		pt[v[p.first]]++;
		pt[v[p.second + 1]]--;
	}
	int maxi = 0;
	vector<int> cover(sz(coords) + 9);
	vector<int> pref(sz(coords) + 10);
	cover[0] = pt[0];
	for (int i = 1; i < sz(pt); i++) { 
        cover[i] = cover[i - 1] + pt[i]; 
    }

	for(int i = 0; i < sz(cover); i++){
    	pref[i] = (i > 0 ? pref[i-1] : 0) + (cover[i] == 1 ? 1 : 0);
    }

	int idx = 1;
	for (auto [l, r] : tmp) {
		int delta = pref[v[r]] - (v[l] - 1 < 0 ? 0 : pref[v[l] - 1]);
		if (delta == 0) {
			cout << idx << '\n';
			return;
		}
		idx++;
	}
	cout << "-1\n";
}
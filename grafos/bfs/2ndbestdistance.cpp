void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> anime(n);
	vector<pair<int, int>> primero(n, {-1, -1}), segundo(n, {-1, -1});
	queue<int> cola;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		anime[x] = 1;
		cola.push(x);
		primero[x] = {0, x};
	}
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	while (!cola.empty()) {
		int u = cola.front();
		cola.pop();
		for (int v : adj[u]) {
			if (primero[u].second != -1) {
				if (primero[u].second != primero[v].second and
					primero[u].second != segundo[v].second) {
					if (primero[v].second == -1) {
						primero[v] = {primero[u].first + 1, primero[u].second};
						cola.push(v);
					} else if (segundo[v].second == -1 or primero[u].first +1< segundo[v].first) {
						segundo[v] = {primero[u].first + 1, primero[u].second};
						cola.push(v);
					}
				}
			}
			if (segundo[u].second != -1) {
				if (segundo[u].second != primero[v].second and
					segundo[u].second != segundo[v].second) {
					if (primero[v].second == -1) {
						primero[v] = {segundo[u].first + 1, segundo[u].second};
						cola.push(v);
					} else if (segundo[v].second == -1 or segundo[u].first +1< segundo[v].first) {
						segundo[v] = {segundo[u].first + 1, segundo[u].second};
						cola.push(v);
					}
				}
			}
		}
	}
    for(int i = 0; i<n;i++){
        if(anime[i]){
            cout<<segundo[i].first<<' ';
        }else{
            cout<<primero[i].first<<' ';
        }
    }
	cout << '\n';
}

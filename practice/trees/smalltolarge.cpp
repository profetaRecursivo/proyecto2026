//Dar la suma de los colores con maxima frecuencia por cada subarbol
int n;
vector<int> colores;
vector<vector<int>> adj;
vector<map<int, int>> conjuntos;
vector<int> ans;
vector<int> maxfrec;
 
void dfs(int nodo, int padre) {
	for (int vecino : adj[nodo]) {
		if (vecino != padre) dfs(vecino, nodo);
	}
	int bigchild = -1;
	for (int vecino : adj[nodo]) {
		if (vecino == padre) continue;
		if (bigchild == -1 or sz(conjuntos[vecino]) > sz(conjuntos[bigchild]))
			bigchild = vecino;
	}
	if (bigchild != -1) {
		swap(conjuntos[nodo], conjuntos[bigchild]);
		maxfrec[nodo] = maxfrec[bigchild];
		ans[nodo] = ans[bigchild];
	} else {
		maxfrec[nodo] = 0;
		ans[nodo] = 0;
	}
	int f = ++conjuntos[nodo][colores[nodo]];
	if (f > maxfrec[nodo]) {
		maxfrec[nodo] = f;
		ans[nodo] = colores[nodo];
	} else if (f == maxfrec[nodo]) {
		ans[nodo] += colores[nodo];
	}
	for (int vecino : adj[nodo]) {
		if (vecino == padre or vecino == bigchild) continue;
		for (auto &[col, freccolor] : conjuntos[vecino]) {
			int nuevafrec = (conjuntos[nodo][col] += freccolor);
			if (nuevafrec > maxfrec[nodo]) {
				maxfrec[nodo] = nuevafrec;
				ans[nodo] = col;
			} else if (nuevafrec == maxfrec[nodo]) {
				ans[nodo] += col;
			}
		}
	}
}
 
void solve() {
	cin >> n;
	colores.assign(n + 1, 0);
	adj.assign(n + 1, {});
	conjuntos.assign(n + 1, map<int, int>());
	ans.assign(n + 1, 0);
	maxfrec.assign(n + 1, 0);
 
	fore(i, 1, n + 1) cin >> colores[i];
	fore(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	dfs(1, -1);
	fore(i, 1, n + 1) cout << ans[i] << ' ';
    cout<<'\n';
}
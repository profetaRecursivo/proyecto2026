//Small to large, dar la cantidad de "colores" diferentes por cada subarbol
const int tam = 2 * 1e5 + 10;
vector<set<int>> conjuntos(tam);
vector<int> ans(tam);
vector<int> color(tam);
void dfs(int nodo, int padre, vector<vi>& g) {
	for (int vecino : g[nodo]) {
		if (vecino != padre) { dfs(vecino, nodo, g); }
	}
	int bigchild = -1;
	for (int vecino : g[nodo]) {
		if (vecino == padre) continue;
		if (bigchild == -1 or sz(conjuntos[vecino]) > sz(conjuntos[bigchild])) {
			bigchild = vecino;
		}
	}
 
	if (bigchild != -1) { swap(conjuntos[nodo], conjuntos[bigchild]); }
	conjuntos[nodo].insert(color[nodo]);
	for (int vecino : g[nodo]) {
		if (vecino == padre or vecino == bigchild) continue;
		for (int colorsito : conjuntos[vecino]) {
			conjuntos[nodo].insert(colorsito);
		}
	}
	ans[nodo] = sz(conjuntos[nodo]);
}
 
void solve() {
	int n;
	cin >> n;
	fore(i, 1, n+1) cin >> color[i];
	vector<vector<int>> g(n + 1);
	fore(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    dfs(1, -1, g);
    fore(i, 1, n+1)cout<<ans[i]<<" ";
}
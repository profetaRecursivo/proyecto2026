void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int& i : arr) cin >> i;
	int k;
	cin >> k;
	sort(all(arr));
	vector<int> nuevo = arr;
	nuevo.insert(nuevo.end(), all(arr));
	auto f = [&](int l)->int {
		l *= 2;
		// primero calculo el next de cada hidrante
		vector<int> next(n), cub(n);
		for (int i = 0; i < n; i++) {
			int cubiertas;
			int x = arr[i] + l;
			auto it = upper_bound(arr.begin() + i, arr.end(), x);
			if (it == arr.end()) {
				int dist = x - tam;
				it = upper_bound(all(arr), dist);
				if (it == arr.end()) {
					// ya retorno true porque solo este hidrante ya se comio
					// todo
					// cubiertas = (n - i) + (it - arr.begin());
                    //que le asigno aqui si ya se paso del circulo
                    next[i] = 0;
                    return 1;
				} else {
					auto yo = arr.begin() + i;
					if (it < yo) {
						next[i] = it - arr.begin();
						cubiertas = (n - i) + (it - arr.begin());
					} else {
                        return 1;
					}
				}
			} else {
				next[i] = it - arr.begin();
				cubiertas = it - (arr.begin() + i);
			}
			cub[i] = cubiertas;
		}
		// ya tengo el salto de 1 puedo calcular facil el de k con binary
		// lifting, pero como hago para probar?
        int logk = (int)(log2(k))+1;
        vector<vector<int>> bl(n, vector<int>(logk)), acum(n, vector<int>(logk));
        for(int i = 0; i<n; i++){
            bl[i][0] = next[i];
            acum[i][0] = cub[i];
        }
        for(int bit = 1; bit < logk; bit++){
            for(int i = 0; i<n; i++){
                bl[i][bit] = bl[bl[i][bit-1]][bit-1];
                acum[i][bit] = acum[i][bit-1] + acum[bl[i][bit-1]][bit-1];
            }
        }
        
        for(int i = 0; i<n;i++){
            int nodo = i;
            int sumatotal = 0;
            for(int bit = 0; bit<logk; bit++){
                if(k>>bit&1){
                    sumatotal+=acum[nodo][bit];
                    nodo = bl[nodo][bit];
                }
            }
            if(sumatotal >=n)return 1;
        }
        return 0;
	};
	int l = 0, r = tam;
	int ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (f(mid)) {
			ans = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	assert(ans != -1);
	cout << ans << '\n';
}
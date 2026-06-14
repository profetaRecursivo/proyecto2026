struct Mo {
	int n;
	int block;
	int current;
	vector<int> arreglo;
	int tam_bloque_val;
	vector<int> frec;
	vector<int> frec_bloque;
	int max_valor;

	struct Query {
		int l, r, id;
	};

	vector<Query> queries;
  //coompresion de coordenadas obligatoria
	Mo(int _n, const vector<int>& _arreglo, int _max_valor) : n(_n), arreglo(_arreglo), max_valor(_max_valor) { 
		block = sqrt(n) + 1; 
		tam_bloque_val = sqrt(max_valor) + 1;
		frec.assign(max_valor + 2, 0);
		frec_bloque.assign((max_valor / tam_bloque_val) + 2, 0);
	}

	void addQuery(int l, int r, int id) { queries.push_back({l, r, id}); }

	inline void actualizar(int val, int delta) {
		frec[val] += delta;
		frec_bloque[val / tam_bloque_val] += delta;
	}

	inline int consultar_menores(int val) {
		int res = 0;
		int id_bloque = val / tam_bloque_val;
		for (int i = 0; i < id_bloque; ++i) {
			res += frec_bloque[i];
		}
		for (int i = id_bloque * tam_bloque_val; i < val; ++i) {
			res += frec[i];
		}
		return res;
	}

	inline int consultar_mayores(int val) {
		int res = 0;
		int id_bloque = val / tam_bloque_val;
		int limite_bloque = (id_bloque + 1) * tam_bloque_val;
		for (int i = val + 1; i < limite_bloque && i <= max_valor; ++i) {
			res += frec[i];
		}
		int max_bloques = (max_valor / tam_bloque_val) + 1;
		for (int i = id_bloque + 1; i <= max_bloques; ++i) {
			res += frec_bloque[i];
		}
		return res;
	}

	inline void addLeft(int idx) {
		int val = arreglo[idx];
		current += consultar_menores(val);
		actualizar(val, 1);
	}
	inline void addRight(int idx) {
		int val = arreglo[idx];
		current += consultar_mayores(val);
		actualizar(val, 1);
	}
	inline void removeLeft(int idx) {
		int val = arreglo[idx];
		actualizar(val, -1);
		current -= consultar_menores(val);
	}
	inline void removeRight(int idx) {
		int val = arreglo[idx];
		actualizar(val, -1);
		current -= consultar_mayores(val);
	}

	vector<int> process() {
		auto cmp = [&](const Query& a, const Query& b) {
			int bl1 = a.l / block;
			int bl2 = b.l / block;
			if (bl1 != bl2) return bl1 < bl2;
			if (bl1 & 1) return a.r > b.r;
			return a.r < b.r;
		};

		sort(all(queries), cmp);

		vector<int> ans(sz(queries));

		int L = 0, R = -1;
		current = 0;
		for (auto& q : queries) {
			while (L > q.l) addLeft(--L);
			while (R < q.r) addRight(++R);
			while (L < q.l) removeLeft(L++);
			while (R > q.r) removeRight(R--);
			ans[q.id] = current;
		}
		return ans;
	}
};
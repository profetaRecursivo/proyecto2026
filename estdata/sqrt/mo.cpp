struct Mo {
	int n;
	int block;
	int current;
	struct Query {
		int l, r, id;
	};

	vector<Query> queries;

	Mo(int n) : n(n) { block = sqrt(n) + 1; }

	void addQuery(int l, int r, int id) { queries.push_back({l, r, id}); }

	inline void addLeft(int idx) {}
	inline void addRight(int idx) {}
	inline void removeLeft(int idx) {}
	inline void removeRight(int idx) {}

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
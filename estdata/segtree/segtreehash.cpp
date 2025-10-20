const ull MOD1 = 1000000007ULL;
const ull MOD2 = 1000000009ULL;
const ull P1 = 1777771ULL;
const ull P2 = 19260817ULL;
struct SegmentTree {
	struct Node {
		ull h1, h2;
		int len;
		Node(ull _h1 = 0, ull _h2 = 0, int _len = 0)
			: h1(_h1), h2(_h2), len(_len) {}
	};

	int n;
	vector<Node> st;
	vector<ull> p1, p2;

	SegmentTree(const vector<int>& a) {
		n = (int)a.size();
		st.assign(4 * n, Node());
		p1.assign(n + 1, 1);
		p2.assign(n + 1, 1);
		precomputePowers();
		build(1, 0, n - 1, a);
	}

	void precomputePowers() {
		p1[0] = p2[0] = 1;
		for (int i = 1; i <= n; ++i) {
			p1[i] = (p1[i - 1] * P1) % MOD1;
			p2[i] = (p2[i - 1] * P2) % MOD2;
		}
	}

	Node merge(const Node& L, const Node& R) {
		ull nh1 = ((L.h1 + (R.h1 * p1[L.len]) % MOD1)) % MOD1;
		ull nh2 = ((L.h2 + (R.h2 * p2[L.len]) % MOD2)) % MOD2;
		return Node(nh1, nh2, L.len + R.len);
	}

	void build(int p, int l, int r, const vector<int>& a) {
		if (l == r) {
			ull v1 = (ull)(a[l] % (int)MOD1);
			ull v2 = (ull)(a[l] % (int)MOD2);
			st[p] = Node(v1, v2, 1);
			return;
		}
		int m = (l + r) >> 1;
		build(p << 1, l, m, a);
		build(p << 1 | 1, m + 1, r, a);
		st[p] = merge(st[p << 1], st[p << 1 | 1]);
	}

	void update(int p, int l, int r, int idx, int val) {
		if (l == r) {
			ull v1 = (ull)(val % (int)MOD1);
			ull v2 = (ull)(val % (int)MOD2);
			st[p] = Node(v1, v2, 1);
			return;
		}
		int m = (l + r) >> 1;
		if (idx <= m)
			update(p << 1, l, m, idx, val);
		else
			update(p << 1 | 1, m + 1, r, idx, val);
		st[p] = merge(st[p << 1], st[p << 1 | 1]);
	}
	void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

	Node queryNode(int p, int l, int r, int ql, int qr) {
		if (qr < l or ql > r) return Node(0, 0, 0);
		if (ql <= l and r <= qr) return st[p];
		int m = (l + r) >> 1;
		Node L = queryNode(p << 1, l, m, ql, qr);
		Node R = queryNode(p << 1 | 1, m + 1, r, ql, qr);
		return merge(L, R);
	}
	pair<ull, ull> query(int l, int r) {
		Node res = queryNode(1, 0, n - 1, l, r);
		return {res.h1, res.h2};
	}
};
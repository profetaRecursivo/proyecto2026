#define lsb(x) ((x) & (-x))
struct BIT {
	// indexado a 1
	vector<int> bit;
	BIT(int N) : bit(N + 1) {}
	void add(int i, int x) {
		while (i < sz(bit)) {
			bit[i] += x;
			i += lsb(i);
		}
	}
	int sum(int i) {
		int ans = 0;
		while (i > 0) {
			ans += bit[i];
			i -= lsb(i);
		}
		return ans;
	}
	int sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};
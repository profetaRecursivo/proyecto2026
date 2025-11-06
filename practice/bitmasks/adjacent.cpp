// You're given an array a of length n
// . For each index i
//  such that 1≤i<n
// , you can perform the following operation at most once:
// Assign ai:=ai xor ai+1
// You can choose indices and perform the operations in any sequential order.

// Given another array b
//  of length n
// , determine if it is possible to transform a
//  to b
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, n) cin >> b[i];
 
	if (a.back() != b.back()) {
		cout << "NO\n";
		return;
	}
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] == b[i]) continue;
		if ((a[i] ^ a[i + 1]) == b[i]) continue;
		if ((a[i] ^ b[i + 1]) == b[i]) continue;
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
 
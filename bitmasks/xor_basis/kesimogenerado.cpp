// ksimo mas grande generado por la base
vector<ull> B;
void insertBasis(ull x) {
	for (ull b : B) x = min(x, x ^ b);
	if (!x) return;
	for (ull &b : B) b = min(b, b ^ x);
	B.push_back(x);
	sort(B.begin(), B.end());
}
int main() {  // con la base actual  cual es el ksimo mas grande?
	int x;
	cin >> x;
	ull k = x;
	if (k > (1ULL << sz(basis))) {
		cout << "-1\n";
		continue;
	}
	k--;  // convertir a 0-index
	ull res = 0;
	for (int i = 0; i < sz(basis); i++) {
		if (k & (1ULL << i)) res ^= basis[i];
	}
	cout << res << "\n";
}
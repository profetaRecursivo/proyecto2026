/*dado arreglo de n elementos responde queries del tipo 
que subset tiene como xor = x?
n=sz, b = 61 la base complejidad:
O(n^2 *B/64 + q*n(1+B/64))*/
const int tam = 61;
const int sz = 500;
void solve() {
	int n;
	cin >> n;
	vector<pair<int, bitset<sz>>> basis(tam, {0, -1});
	for (int i = 0; i < n; i++) {
		int x;cin >> x;
		bitset<sz> bs;
		bs[i] = 1;
		for (int j = tam - 1; j >= 0; j--) {
			if (x & (1LL << j)) {
				if (!basis[j].first) {
					basis[j].first = x;
					swap(basis[j].second, bs);
					break;
				} else
					x ^= basis[j].first, bs ^= basis[j].second;
			}
		}
	}
	while (q--) {
		int x;cin>>x;
		bitset<sz> bs;
		for (int i = tam - 1; i >= 0; i--) {
			if (x & (1LL << i)) {
				if (basis[i].first) x ^= basis[i].first, bs ^= basis[i].second;
			}
		}//esto solo sirve si esta garantizado que basis[i].first == 0
		for (int i = 0; i < n; i++) cout << bs[i];
	}
}
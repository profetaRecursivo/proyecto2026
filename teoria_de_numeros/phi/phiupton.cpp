vector<int> phi(tam + 1);
void euler() {
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
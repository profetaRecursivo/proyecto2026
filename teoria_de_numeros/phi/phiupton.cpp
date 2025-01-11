vector<int> phi(tam + 1);
void euler(int tam) {
	for (int i = 0; i <= tam; i++) phi[i] = i;
	for (int i = 2; i <= tam; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= tam; j += i) phi[j] -= phi[j] / i;
		}
	}
}
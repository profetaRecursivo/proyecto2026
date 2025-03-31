int C[tam + 1][tam + 1];
void prec() {
	C[0][0] = 1;
	for (int n = 1; n <= tam; ++n) {
		C[n][0] = C[n][n] = 1;
		for (int k = 1; k < n; ++k) 
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}
}
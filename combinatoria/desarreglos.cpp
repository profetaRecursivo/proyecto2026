void precdes() {
	des[0] = 1;
	des[1] = 0;	
	for (int i = 2; i < tam; ++i) {
		des[i] = (i - 1) * ((des[i - 1] + des[i - 2]) % MOD) % MOD;
	}
}
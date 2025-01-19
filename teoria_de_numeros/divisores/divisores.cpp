//raiz de n
vector<int> divisores(int n) {
	vector<int> divs;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divs.push_back(i);
			if (i != n / i) { divs.push_back(n / i); }
		}
	}
	return divs;
}


ll divisores(ll num) {
    ll total = 1;
    for (int i = 2; (ll)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	ll g = extended_gcd(a, m, x, y);
	if (g != 1) return -1;	// no tiene inverso
	return (x % m + m) % m;
}

void solve() {
	ll a, b, m;
	cin >> a >> b >> m;

	m = abs(m);
	a = (a % m + m) % m;
	b = (b % m + m) % m;

	ll g = gcd(a, m);
	if (g == 0) {
		cout << (b == 0 ? "0\n" : "No hay solucion\n");
		return;
	}

	if (g == 1) {
		ll inv = mod_inverse(a, m);
		if (inv == -1)
			cout << "No hay solucion\n";
		else
			cout << (b * inv) % m << '\n';
	} else if (b % g == 0) {
		a /= g;
		b /= g;
		m /= g;
		ll inv = mod_inverse(a, m);
		if (inv == -1)
			cout << "No hay solucion\n";
		else {
			ll x0 = (b * inv) % m;
			// imprime todas las sol
			for (int k = 0; k < g; k++) {
				ll sol = x0 + k * m;
				cout << sol;
				if (k < g - 1) cout << " ";
			}
			cout << '\n';
		}
	} else
		cout << "No hay solucion\n";
}
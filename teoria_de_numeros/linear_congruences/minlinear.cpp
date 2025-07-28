ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

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
    if (g != 1) return -1;
    return (x % m + m) % m;
}

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    m = abs(m);
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    if (a == 0) {
        if (b == 0) cout << "0 " << m-1 << "\n"; // Todas las soluciones
        //que existen
        else cout << "No hay solucion\n";
        return;
    }

    ll g = gcd(a, m);
    
    if (b % g != 0) {
        cout << "No hay solucion\n";
        return;
    }
    
    if (g == 1) {
        ll inv = mod_inverse(a, m);
        if (inv == -1) cout << "No hay solucion\n";
        else {
            ll sol = (b * inv) % m;
            cout << sol << " " << sol << "\n"; // unica sol
        }
    } else {
        ll ap = a / g;
        ll bp = b / g;
        ll mp = m / g;
        
        ll inv = mod_inverse(ap, mp);
        if (inv == -1) cout << "No hay solucion\n";
        else {
            ll x0 = (bp * inv) % mp;
            x0 = (x0 + mp) % mp;
            ll min_sol = x0;
            ll max_sol = x0 + (g - 1) * mp;
            cout << min_sol << " " << max_sol << "\n";
        }
    }
}
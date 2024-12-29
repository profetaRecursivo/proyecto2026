//Si queremos (a*b)mod m pero (a mod m)*(b mod  m) desborda los enteros entonces:
//Usamos mulmod en log a
//extra: para hacerlo mas eficiente 
//llamar la funcion como mulmod(min(a, b), max(a, b), m)
int mulmod(int a, int b, int m) {
    int ans = 0; 
    while (a > 0) {
        if (a&1) {
            ans = (ans + b) % m;
        }
        b = (b<<1) % m;
        a>>=1;
    }
    return ans; 
}

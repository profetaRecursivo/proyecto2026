ll s(ll p, ll e){
    ll num = (expmod(p, e + 1) - 1 + MOD) % MOD;
    ll den = (p - 1 + MOD) % MOD;
    return num * inv(den) % MOD;
}
//contribucion de p^e a la suma de divisores
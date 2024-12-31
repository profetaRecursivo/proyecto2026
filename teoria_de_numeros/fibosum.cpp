/*
Suma de los fibonaccis desde a hasta b
sum(fibo    (0..n)) = fibo_{n+2} - 1
*/
pair<int, int> fib_mod(int n, int m) {
    if (n <= 0)
        return {0, 1};

    auto p = fib_mod(n >> 1, m);
    int c = (p.first * (2LL * p.second % m - p.first + m) % m) % m;
    int d = (1LL * p.first * p.first % m + 1LL * p.second * p.second % m) % m;

    if (n & 1)
        return {d, (c + d) % m};
    else
        return {c, d};
}
void solve(){
    int a, b;cin>>a>>b;
    int l = fib_mod(a+1, MOD).first - 1 ;
    l+=MOD;
    l%=MOD;
    int r = fib_mod(b+2,MOD).first - 1;
    r+=MOD;
    r%=MOD;
    int ans = r - l + MOD;
    ans%=MOD;
    cout<<ans<<endl;
}
#define bint __int128 //indexado a 1
struct Hash {
  bint MOD=212345678987654321LL, P=1777771, 
  PI=106955741089659571LL;
  vector<bint> h, pi;
  Hash(string s) {
    s = ' ' + s; 
    int n = s.size() - 1; 
    assert((P * PI) % MOD == 1);
    h.resize(n + 2); pi.resize(n + 2);
    h[0] = 0; pi[0] = 1;
    bint p = 1;
    for (int i = 1; i <= n; ++i) {
      h[i] = (h[i - 1] + p * s[i]) % MOD;
      pi[i] = (pi[i - 1] * PI) % MOD;
      p = (p * P) % MOD;
    }
  }

  long long get(int l, int r) {
    return (((h[r] - h[l - 1] + MOD) % MOD) * pi[l - 1]) % MOD;
  }
};
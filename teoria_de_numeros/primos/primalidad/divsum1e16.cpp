// Given a natural number n (1 ≤ n ≤ 1e16), please output the summation of all its proper divisors.
#include "bits/stdc++.h"
#define int long long
using namespace std;

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

int mulmod(int a, int b, int m) {
  int r = a * b - (int)((long double)a * b / m + .5) * m;
  return r < 0 ? r + m : r;
}

int expmod(int b, int e, int m) {
  if (!e)
    return 1;
  int q = expmod(b, e / 2, m);
  q = mulmod(q, q, m);
  return e & 1 ? mulmod(b, q, m) : q;
}

bool is_prime_prob(int n, int a) {
  if (n == a)
    return true;
  int s = 0, d = n - 1;
  while (d % 2 == 0)
    s++, d /= 2;
  int x = expmod(a, d, n);
  if ((x == 1) || (x + 1 == n))
    return true;
  for (int i = 0; i < s - 1; ++i) {
    x = mulmod(x, x, n);
    if (x == 1)
      return false;
    if (x + 1 == n)
      return true;
  }
  return false;
}

bool rabin(int n) {
  if (n == 1)
    return false;
  int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  for (int i = 0; i < 9; ++i) {
    if (!is_prime_prob(n, ar[i]))
      return false;
  }
  return true;
}

const int MAXP = 1e7 + 1;
int sv[MAXP];          

void init_sv() {
  for (int i = 2; i < MAXP; ++i) {
    if (!sv[i]) {
      for (int j = i; j < MAXP; j += i)
        sv[j] = i;
    }
  }
}

int add(int a, int b, int m) { return (a += b) < m ? a : a - m; }

int rho(int n) {
  static int s[MAXP];
  while (true) {
    int x = rand() % n, y = x, c = rand() % n;
    int *px = s, *py = s, v = 0, p = 1;
    while (true) {
      *py++ = y = add(mulmod(y, y, n), c, n);
      *py++ = y = add(mulmod(y, y, n), c, n);
      if ((x = *px++) == y)
        break;
      int t = p;
      p = mulmod(p, abs(y - x), n);
      if (!p)
        return gcd(t, n);
      if (++v == 26) {
        if ((p = gcd(p, n)) > 1 && p < n)
          return p;
        v = 0;
      }
    }
    if (v && (p = gcd(p, n)) > 1 && p < n)
      return p;
  }
}

void fact(int n, map<int, int> &ff) {
  while (n % 2 == 0) {
    ff[2]++;
    n /= 2;
  }

  int limit = pow(n, 0.25);
  for (int i = 3; i <= limit; i += 2) {
    while (n % i == 0) {
      ff[i]++;
      n /= i;
    }
  }
  if (n > 1) {
    if (rabin(n)) {
      ff[n]++;
    } else {
      int q = rho(n);
      fact(q, ff);     
      fact(n / q, ff); 
    }
  }
}
int binpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int causa(int a, int b) {
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    ans += binpow(a, i);
  }
  return ans;
}
signed main() {
  init_sv(); // Inicializa la criba
  int t;
  cin >> t;
  while (t--) {
    map<int, int> ff;
    int n;
    cin >> n;
    fact(n, ff);
    int ans = 1;
    // cout<<"asdasddsa"<<(int)(ff.size())<<endl;
    for (auto &p : ff) {
      ans *= causa(p.first, p.second);
    }
    cout << ans - n<< endl;
  }

  return 0;
}
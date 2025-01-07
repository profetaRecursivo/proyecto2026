
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
 
const int MAXP = 1e6 + 1;

 
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

signed main() {
  int n;cin>>n;
  map<int, int> facts;
  fact(n, facts);
  int ans = 1;
  for(auto[_, exp]:facts){
    ans*=(exp+1);
  }
  cout<<ans<<endl;
}
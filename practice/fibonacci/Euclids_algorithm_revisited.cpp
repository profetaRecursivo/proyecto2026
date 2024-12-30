#include "bits/stdc++.h"
#define int long long
using namespace std;
const int MOD = 1000000007;

pair<int, int> fib_mod(int n, int m) {
  if (n == 0)
    return {0, 1};
  auto p = fib_mod(n >> 1, m);
  int c = (p.first * (2LL * p.second % m - p.first + m) % m) % m;
  int d = (1LL * p.first * p.first % m + 1LL * p.second * p.second % m) % m;
  if (n & 1)
    return {d, (c + d) % m};
  else
    return {c, d};
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if(x==0){
        cout<<0<<endl;
    }else if(x == 1){
        cout<<2<<endl;
    }else{
        cout<<fib_mod(x+3, MOD).first<<endl;
    }
  }
}

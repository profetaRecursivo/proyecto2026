// Contar, para cada (l, x) cuantas subsecuencias de los primeros l elementos tienen XOR = x
const int tam = 22;
int basis[tam];
int sz = 0;
void insertar(int x) {
  for (int i = tam - 1; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!basis[i]) {
        basis[i] = x;
        sz++;
        return;
      }
      x ^= basis[i];
    }
  }
}
void reducir(int &x) {
  for (int i = tam - 1; i >= 0; --i) {
    if (x & (1 << i)) {
      if (basis[i]) {
        x ^= basis[i];
      }
    }
  }
}
 
ll expmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve() {
  memset(basis, 0, sizeof basis);
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  map<int, vector<pair<int, int>>> queries;
 
  for (int i = 0; i < q; i++) {
    int l, x;
    cin >> l >> x;
    queries[l].push_back({x, i});
  }
  vector<int> ans(q);
  for (int i = 1; i <= n; i++) {
    // ahora inserto y pregunto
    insertar(arr[i]);
    for (pair<int, int> &x : queries[i]) {
      // ver cuantas son
      reducir(x.first);
      int res = 0;
      if (x.first == 0) {
        res = expmod(2, i - sz, MOD);
      }
      ans[x.second] = res;
    }
  }
  for (int chamo : ans)
    cout << chamo << '\n';
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  //   cin>>t;
  while (t--) {
    solve();
  }
}
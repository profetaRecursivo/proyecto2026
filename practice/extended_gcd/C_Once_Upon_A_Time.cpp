#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define sst stringstream
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fore(i, a, n) for(int i = (a); i < (n); i++)
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define popcount(x) __builtin_popcountll(x);
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOd = 1000000007;
const double EpS = 1e-9;
const double pI = acos(-1);
const int INF = 1e18;
//DIO WA por si acaso
//PLUS ULTRA RECARGADO!!!
int extgcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (true) {
        int j, p, q, d;
        cin >> j >> p >> q >> d;
        if (j == 0 && p == 0 && q == 0 && d == 0) break;
        int r = d - j;
        int x, y;
        int g = extgcd(p, q, x, y);
        if (r % g) {
            cout << "Impossible\n";
            continue;
        }
        x = x * (r / g);
        int lcm = (p / g) * q;
        int k = ((x % (q / g)) + (q / g)) % (q / g);
        int t = j + k * p;
        cout << t << '\n';
    }
    return 0;
}
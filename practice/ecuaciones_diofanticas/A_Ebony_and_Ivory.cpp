/*
me dice si ax + by = c
con a b c de entrada tiene soluciones x y >=0 
*/
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
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = 1e18;
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

void solve(){
    vector<int> arr(n);
    int a, b, c;cin>>a>>b>>c;
    int gcd, x0, y0;
    gcd = extgcd(a, b, x0, y0);
    if (c % gcd != 0) {
        cout<<"No\n";
        return;
    }
    int esc = c / gcd;
    x0 *= esc;
    y0 *= esc;
    int na = a / gcd;
    int nb = b / gcd;
    int mini = ceil(-1.0 * x0 / nb);
    int maxi = floor(1.0 * y0 / na);
    cout<<(mini<=maxi?"Yes\n":"No\n");
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}

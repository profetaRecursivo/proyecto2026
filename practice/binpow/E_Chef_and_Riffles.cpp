/*ya sabes
aplicar k permutaciones, en este caso es 1,3,5,..,n-1, 2,4,6,...,n*/
/*a la identidad que saco con getperm*/
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
vi getperm(int n){
    vi ans;
    for(int i = 1; i<=n; i+=2){
        ans.push_back(i);
    }
    for(int i = 2; i<=n; i+=2){
        ans.push_back(i);
    }
    for(int& i:ans)--i;
    return ans;
}
vi applyperm(vi& secuencia, vi& permutacion) {
    vi ans(secuencia.size());
    for (int i = 0; i < secuencia.size(); i++) {
        ans[i] = secuencia[permutacion[i]];
    }
    return ans;
}

vi permutar(vi secuencia, vi permutacion, long long k) {
    while (k > 0) {
        if (k & 1) {
            secuencia = applyperm(secuencia, permutacion);
        }
        permutacion = applyperm(permutacion, permutacion);
        k >>= 1;
    }
    return secuencia;
}
void solve() {
    int n, k;cin>>n>>k;
    vi sec;
    for(int i =1; i<=n; i++)sec.push_back(i);
    auto p = permutar(sec, getperm(n), k);
    for(int i:p)cout<<i<<' ';
    cout<<'\n'; 
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--)solve();
}
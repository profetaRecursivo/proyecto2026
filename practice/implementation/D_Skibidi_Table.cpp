#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
bool dentro(int val, pair<int, int> p){
    return val >= p.first and val <= p.second;
}
pair<int, int> findpos(int x, int y, int n, int mini, int maxi, int val){
    if(n == 0){
        return {x, y};
    }else{
        //a que cuadrante debo ir?
        // 1 -> entre [mini, mini + 4^(n-1) -1 ];
        // 2 -> [mini + 4^(n-1), mini + 4(^n-1) + 4^(n-1) - 1]
        // 3 -> [mini + 2*4^(n-1), mini + 3*4^(n-1) - 1]
        // 4 -> [mini + 3*4^(n-1), maxi]
        int pot = 1LL<<((n-1)<<1);
        int longi = 1LL<<(n-1);
        pair<int, int> a = {mini, mini + pot-1};
        pair<int, int> b = {mini + pot, mini + 2*pot - 1};
        pair<int, int> c = {mini + 2*pot, mini + 3*pot - 1};
        pair<int, int> d = {mini + 3*pot, maxi};
        if(dentro(val, a)){
            int nx = x - longi;
            int ny = y - longi;
            return findpos(nx, ny, n-1, a.first, b.second, val);
        }else if(dentro(val, b)){
            int nx = x;
            int ny = y;
            return findpos(nx, ny, n-1, b.first, b.second, val);
        }else if(dentro(val, c)){
            int nx = x;
            int ny = y - longi;
            return findpos(nx, ny, n-1, c.first, c.second, val);
        }else{
            int nx = x - longi;
            int ny = y;
            return findpos(nx, ny, n-1, d.first, d.second, val);
        }
    }
}

int findelement(int x, int y, int n, int act) {
    if (n == 1) {
        if (x % 2 == 0 and y % 2 == 0) return act + 1;
        if (x % 2 == 1 and y % 2 == 1) return act + 2; 
        if (x % 2 == 1 and y % 2 == 0) return act + 3;
        if (x % 2 == 0 and y % 2 == 1) return act + 4;
    }

    int longi = 1 << (n - 1); 
    int pot = longi * longi;

    if (x < longi and y < longi) {
        return findelement(x, y, n - 1, act);
    } else if (x >= longi and y >= longi) {
        return findelement(x - longi, y - longi, n - 1, act + pot);
    } else if (x >= longi and y < longi) {
        return findelement(x - longi, y, n - 1, act + 2 * pot);
    } else {
        return findelement(x, y - longi, n - 1, act + 3 * pot);
    }
}



void solve(){
    ll n, q;cin>>n>>q;
    while(q--){
        string s;cin>>s;
        if(s == "->"){
            int x, y;cin>>x>>y;
            int maxi = 1LL<<(n<<1);
            int elem = findelement(x-1, y-1, n, 0);
            cout<<elem<<endl;
        }else{
            int x;cin>>x;
            int maxi = 1LL<<(n<<1);
            auto pos = findpos(1LL<<n, 1LL<<n, n, 1LL, maxi, x);
            cout<<pos.first<<' '<<pos.second<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
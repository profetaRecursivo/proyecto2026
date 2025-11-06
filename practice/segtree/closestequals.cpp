// minimum distance between such pair of elements a_x and a_y (x ≠ y), that:
// both indexes of the elements lie within range [lj, rj], that is, lj ≤ x, y ≤ rj;
// the values of the elements are equal, that is ax = ay.
// The text above understands distance as |x - y|.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = LLONG_MAX;

const int tam = 1<<19;
struct Node
{
    int mini;
    Node(int _x = INF){
        mini = _x;
    }
    static inline Node merge(const Node& a, const Node&b){
        return Node(min(a.mini, b.mini));
    }
};
int n;
Node t[2*tam];
void build(){
    for(int i = n-1; i>0; --i){
        t[i]= Node::merge(t[i<<1], t[(i<<1)|1]);
    }
}
void update(int p, Node value){
    for(t[p+=n] = value; p>1; p>>=1){
        t[p>> 1] = Node::merge(t[p], t[p^1]);
    }
}
Node query(int l, int r){
    r++;
    Node izq, der;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) izq = Node::merge(izq, t[l++]);
        if(r&1) der = Node::merge(der, t[--r]);
    }
    return Node::merge(izq, der);
}
void solve(){
    int q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> izq;
    int ant[n], nxt[n];
    memset(nxt, -1, sizeof nxt);
    for(int i = 0; i < n; i++){
        auto pos = izq.find(arr[i]);
        if(pos == izq.end()){
            ant[i] = INF;
        } else {
            ant[i] = pos->second;
        }
        izq[arr[i]] = i;
    }
    unordered_map<int, int> der;
    for(int i = n-1; i >= 0; i--){
        auto it = der.find(arr[i]);
        if(it == der.end()){
            nxt[i] = -1;
        } else {
            nxt[i] = it->second;
        }
        der[arr[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(ant[i] != INF) t[n+i] = Node(i - ant[i]);
    }
    build();
    vector<pair<int,int>> queries[n];
    int ans[q];
    int idx = 0;
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        queries[l].push_back({r, idx});
        idx++;
    }
    for(int i = 0; i < n; i++){
        for(auto [r, i_query] : queries[i]){
            auto res = query(i, r);
            ans[i_query] = (res.mini == INF ? -1 : res.mini);
        }
        if(nxt[i] != -1) update(nxt[i], Node(INF));
    }
    for(int reS : ans) cout << reS << '\n';
}
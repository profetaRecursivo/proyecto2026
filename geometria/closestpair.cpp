#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("unroll-loops")
 #define ld long double
#define int long long
#define all(x) (x).begin(), (x).end()
const ld INF_INT = 4e14;
ld dis(pair<ld,ld> a, pair<ld,ld> b){
    ld dx = a.first - b.first;
    ld dy = a.second - b.second;
    return dx*dx + dy*dy;
} 
void solve(int n){
    vector<pair<pair<ld,ld>, int>> ptos(n);
    for(int i=0;i<n;i++){
        ld a,b; cin>>a>>b;
        ptos[i] = {{a,b}, i};
    }
    auto copia = ptos;
    sort(all(ptos)); 
 
    ld best = dis(ptos[0].first, ptos[1].first);
    pair<int,int> mejores = {ptos[0].second, ptos[1].second};
 
    set<pair<pair<ld,ld>, int>> ventana;
 
    int left = 0; 
    for(int i=0;i<n;i++){
        ld x = ptos[i].first.first;
        ld y = ptos[i].first.second;
        int id = ptos[i].second;

        while(left < i){
            ld x_left = ptos[left].first.first;
            ld dx = x - x_left;
            if(dx*dx > best){
                ld y_left = ptos[left].first.second;
                ld id_left = ptos[left].second;
                ventana.erase({{y_left, x_left}, id_left});
                left++;
            } else break;
        }
 
        ld d = sqrtl(best);
        auto it_low  = ventana.lower_bound({{y - d, -INF_INT}, -INF_INT});
        auto it_high = ventana.upper_bound({{y + d, INF_INT}, INF_INT});
 
        for(auto it = it_low; it != it_high; ++it){
            ld x2 = it->first.second;
            ld y2 = it->first.first;
            int id2 = it->second;
            ld dx = x - x2;
            ld dx2 = dx*dx;
            if(dx2 > best) continue;
            ld dy = y - y2;
            ld dist = dx2 + dy*dy;
            if(dist < best){
                best = dist;
                mejores = {id, id2};
            }
        }
        ventana.insert({{y, x}, id});
    }
 
    cout <<fixed<<setprecision(2)<< copia[mejores.first].first.first<<' ' << copia[mejores.first].first.second<<' '<<copia[mejores.second].first.first << ' '<< copia[mejores.second].first.second<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(1){
        int x;cin>>x;
        if(x == 0)break;
        solve(x);
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MAXN = 200000;
 
vector<map<int, int>> colores;
vector<int> valores;
vector<int> res;
 
 
 
void dfs1(int u , int p, vector<vector<int>> &g){
    //dfs normalito
     for(auto v: g[u]){
          if(v == p) continue;
          dfs1(v,u,g);
     }
     //encontramos al hijo con el conjunto mas grande
     int bigChild = -1;
     for(auto v: g[u]){
        if(v == p) continue;
        if(bigChild == -1 || colores[v].size() > colores[bigChild].size()){
            bigChild = v;
        }
     }
    
    //si lo encontramos lo cambiamos, modificacion de punteros
    if(bigChild != -1 && colores[u].size() < colores[bigChild].size()){
        swap(colores[u], colores[bigChild]);
    }
    //le damos el valor inicial
    colores[u][valores[u]]++;
    //unimos todos los conjuntos menos el del bigChild
    for(auto v: g[u]){
        if(v == p || v == bigChild)continue;
        for(auto nodo: colores[v]){
            colores[u][nodo.first] += nodo.second;
        }
    }
    //Guardamos la respuesta para no perder info con 
    //los siguientes swaps
    res[u] = colores[u].size();
 
}
 
 
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    colores.resize(n);
    valores.resize(n);
    res.resize(n);
    vector<vector<int>> g(n);
 
    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    dfs1(0, -1, g);
 
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}
 
signed main() {
    solve();
    return 0;
}
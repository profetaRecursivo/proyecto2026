const int tam = 1e5;
int arr[tam], flat[tam];
vector<int> g[tam];
int timer = 0;
int tin[tam], tout[tam];
void dfs(int u, int p){
    tin[u] = timer++;
    flat[tin[u]] = arr[u];
    for(int v:g[u]){
        if(v == p)continue;
        dfs(v, u);
    }
    tout[u] = timer;
}
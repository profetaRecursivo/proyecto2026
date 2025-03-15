#define type int //long long, int o lo que sea, incluso double
//tupla -> peso, u, v
//indexado a 0
type mst(vector<tuple<type, int, int>>& edges, int n){
    sort(all(edges));
    unionFind dsu(n);
    int cont = 0, ans = 0;
    for(auto[peso, u, v]:edges){
        if(dsu.join(u, v)){
            cont++, ans+=peso;
        }
        if(cont == n-1){
            break;
        }
    }
    return (cont == n-1?ans:-1);
}
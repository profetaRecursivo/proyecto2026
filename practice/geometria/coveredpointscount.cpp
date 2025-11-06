// You are given n
//  segments on a coordinate line; each endpoint of every segment has integer coordinates. Some segments can degenerate to points. Segments can intersect with each other, be nested in each other or even coincide.

// Your task is the following: for every k∈[1..n]
// , calculate the number of points with integer coordinates such that the number of segments that cover these points equals k
// . A segment with endpoints li
//  and ri
//  covers point x
//  if and only if li≤x≤ri
void solve(){
    int n;cin>>n;
    map<int, int> eventos;
    for(int i = 0; i<n; i++){
        int a, b;cin>>a>>b;
        eventos[a]++;
        eventos[b+1]--;
    }
    int pref = 0;
    unordered_map<int, int> ans;
    ans.reserve(n+1);
    //
    int ult = eventos.begin()->first;
    for(auto [posicion, valor]:eventos){
        int cant = posicion - ult;
        ans[pref]+=cant;
        pref+=valor;
        //la cantidad de puntos que tienen pref segmentos que los cubren son r-l+1
        ult = posicion;
    }
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
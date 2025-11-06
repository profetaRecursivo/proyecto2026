// Dado un arreglo de enteros
// para cada segment [l, r] un numero se considera valido si divide a todos los demas numeros del segmento
// Se pide la candtidad de numeros del segmento que NO son validos
const int tam = 100004;

const int N = 1<<17;
int n; 
int trr[2*N]; 

void build() {
    for (int i = n-1; i > 0; --i)
        trr[i] = gcd(trr[i<<1],  trr[i<<1|1]);
}

void modify(int p, int value) {
    for (trr[p += n] = value; p > 1; p >>= 1)
        trr[p>>1] = gcd(trr[p], trr[p^1]);
}

int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans = gcd( ans, trr[l++]);
        if (r&1) ans = gcd( ans, trr[--r]);
    }
    return ans;
}
map<int, vector<int>> pos;
void solve(){
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        scanf("%d", &trr[i+n]);
        pos[trr[i+n]].push_back(i+1);
    }
    build();
    int q;
    scanf("%d", &q);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        int g = query(l-1, r);
        int cant = 0;
        if(pos.find(g) != pos.end()){
            auto a = lower_bound(pos[g].begin(), pos[g].end(), l);
            auto b = upper_bound(pos[g].begin(), pos[g].end(), r);
            cant = b - a;
        }
        printf("%d\n", r-l+1-cant);
    }
}
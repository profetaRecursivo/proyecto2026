//query l a r la maxima A[i] + A[j]
const int INF = 2e9;
const int tam = 1<<18;
struct Node{
    int maxi;
    int idx;
    Node(int _x = -INF, int _i = -1){
        maxi = _x; idx = _i;
    }
    static inline Node merge(const Node& a, const Node& b){
        if(a.maxi > b.maxi) return Node(a.maxi, a.idx);
        else return Node(b.maxi, b.idx);
    }
};
int n;
Node t[2 * tam];

void build(){
    for(int i = n - 1; i > 0; --i){
        t[i] = Node::merge(t[i << 1], t[(i << 1) | 1]);
    }
}

void update(int p, Node value){
    for(t[p += n] = value; p > 1; p >>= 1){
        t[p >> 1] = Node::merge(t[p], t[p ^ 1]);
    }
}

Node query(int l, int r){
    r++;
    Node izq, der;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) izq = Node::merge(izq, t[l++]);
        if(r & 1) der = Node::merge(der, t[--r]); 
    }
    return Node::merge(izq, der);
}


void solve(){
    cin>>n;
   for(int i = 0; i<n; i++){
        int x;cin>>x;
        t[n+i] = Node(x, i);
   }
   build();
   int q;cin>>q;
   while(q--){
    char t;cin>>t;
    if(t == 'U'){
        int pos, x;cin>>pos>>x;
        pos--;
        update(pos, Node(x, pos));
    }else{
        int l, r;cin>>l>>r;
        l--, r--;
        Node prim = query(l, r);
        Node izq, der;
        ll ans = prim.maxi;
        if(prim.idx == r){//el maximo es el ultimo elemento
            izq = query(l, prim.idx-1);
            ans = ans + izq.maxi;
            cerr<<'a';
        }else if(prim.idx == l){//el maximo es el primer
            der = query(prim.idx + 1, r);
            ans = ans + der.maxi;
            cerr<<'b';
        }else{//como el maximo esta en el medio, podemos hacer query de izq y der
            izq = query(l, prim.idx-1);
            der = query(prim.idx+1, r);
            ans +=max(izq.maxi, der.maxi);
            cerr<<'c';
        }
        cout<<ans<<'\n';
        
    }
   }
}
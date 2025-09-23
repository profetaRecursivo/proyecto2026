const int tam = POTENCIA DE DOS;
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
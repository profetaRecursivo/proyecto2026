struct Node{
    int x;
    Node(int _x = 0){
        x = _x;
    }
    static inline Node merge(const Node& a, const Node& b){
        return Node(a.x | b.x);
    }
};
const int N = 1<<17;
int n; 
Node t[2*N]; 

void build() {
    for (int i = n-1; i > 0; --i)
        t[i] = Node::merge(t[i<<1],  t[i<<1|1]);
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p>>1] = Node::merge(t[p], t[p^1]);
}

Node query(int l, int r) {
    Node izq, der;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) izq = Node::merge( izq, t[l++]);
        if (r&1) der = Node::merge( der, t[--r]);
    }
    return Node::merge(izq, der);
}
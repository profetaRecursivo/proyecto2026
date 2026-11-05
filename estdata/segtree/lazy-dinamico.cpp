struct Tag {
    ll add = 0;
    bool empty() const {
        return add == 0;
    }
    void combine(const Tag& t) {
        add += t.add;
    }
};
struct Info {
    ll sum = 0;
    void apply(const Tag& t, ll len) {
        sum += t.add * len;
    }
    static Info merge(const Info& a, const Info& b) {
        return Info{a.sum + b.sum};
    }
};
struct Node {
    Info info;
    Tag tag;
    int32_t izq = 0, der = 0;
};
/*
  CÁLCULO DE MAX_NODES (Persistent Segment Tree):
  M = Tamaño del rango [1, M]
  U = Cantidad total de updates (versiones)
  1. Point Update:
     Nodos/update ≈ log2(M) + 2
     Regla rápida: U * 20
  2. Range Update (Lazy Permanente):
     Nodos/update ≈ 4 * log2(M)   [Peor caso si M no es potencia de 2]
     Regla rápida: U * 70
  CÁLCULO DE MEMORIA (MB):
  MB = (MAX_NODES * sizeof(Node)) / (1024 * 1024)
*/
const int MAX_NODES = 200000*70;
//deberia entrar xd
Node tree[MAX_NODES];
int node_cnt = 0;

int32_t clone_node(int32_t src) {
    int32_t u = ++node_cnt;
    tree[u] = tree[src];
    return u;
}

int update(int node, ll b, ll e, ll i, ll j, const Tag& val) {
    int ans = clone_node(node);
    if (i <= b and e <= j) {
        tree[ans].info.apply(val, e - b + 1);
        tree[ans].tag.combine(val);
        return ans;
    }
    ll mid = b + (e - b) / 2;
    if (j <= mid) {
        tree[ans].izq = update(tree[node].izq, b, mid, i, j, val);
    } else if (i > mid) {
        tree[ans].der = update(tree[node].der, mid + 1, e, i, j, val);
    } else {
        tree[ans].izq = update(tree[node].izq, b, mid, i, j, val);
        tree[ans].der = update(tree[node].der, mid + 1, e, i, j, val);
    }
    
    // Recalcular la informacion combinando los hijos + el tag del nodo actual (Lazy Permanente)
    Info info_izq = tree[tree[ans].izq].info;
    Info info_der = tree[tree[ans].der].info;
    tree[ans].info = Info::merge(info_izq, info_der);
    tree[ans].info.apply(tree[ans].tag, e - b + 1);
    
    return ans;
}

Info query(int node, ll b, ll e, ll i, ll j, Tag tag_acum = Tag()) {
    if (node == 0) {
        ll l = max(b, i);
        ll r = min(e, j);
        if (l > r) return Info();
        Info res = Info();
        res.apply(tag_acum, r - l + 1);
        return res;
    }
    if (i <= b && e <= j) {
        Info res = tree[node].info;
        res.apply(tag_acum, e - b + 1);
        return res;
    }
    ll mid = b + (e - b) / 2;
    Tag cur_tag = tag_acum;
    cur_tag.combine(tree[node].tag);
    if (j <= mid) {
        return query(tree[node].izq, b, mid, i, j, cur_tag);
    }
    if (i > mid) {
        return query(tree[node].der, mid + 1, e, i, j, cur_tag);
    }
    return Info::merge(
        query(tree[node].izq, b, mid, i, j, cur_tag),
        query(tree[node].der, mid + 1, e, i, j, cur_tag)
    );
}
El uso es vector<int> historia={0}; y updatequery en el tiempo t deseado

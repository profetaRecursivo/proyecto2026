const int MAX_NODES = 3526928; //aprox Q * log2(MAX_COORD) +/* algun factor de escala por seguridad
const ll INF = 4e18;
struct Item {
    ll val;
    Item(ll _val = 0){
        val = _val;
    }
   
    static inline Item merge(const Item& left, const Item& right) {
        Item res;
        
        return res;
    }
};

struct Node {
    Item info;
    int left = -1;
    int right = -1;
} tree[MAX_NODES];

int nodes_cnt = 0;
void clear_tree() {
    nodes_cnt = 0;
}
int new_node() {
    int id = ++nodes_cnt;
    tree[id].left = -1;
    tree[id].right = -1;
    tree[id].info = Item();
    return id;
}
Item get_info(int u) {
    if (u == -1) return Item();
    return tree[u].info;
}

void pull(int u) {
    Item l = get_info(tree[u].left);
    Item r = get_info(tree[u].right);
    tree[u].info = Item::merge(l, r);
}
void update(int &u, ll s, ll e, ll pos, Item val) {
    if (u == -1) u = new_node();
    if (s == e) {
        //acumulacion o asignacion?
        tree[u].info = Item::merge(tree[u].info, val); 
        return;
    }
    
    ll mid = s + (e - s) / 2;
    if (pos <= mid)
        update(tree[u].left, s, mid, pos, val);
    else
        update(tree[u].right, mid + 1, e, pos, val);
    pull(u);
}

Item query(int u, ll s, ll e, ll l, ll r) {
    if (u == -1 or s > r or e < l) return Item();
    if (s >= l and e <= r) return tree[u].info;
    ll mid = s + (e - s) / 2;
    return Item::merge(query(tree[u].left, s, mid, l, r),
                       query(tree[u].right, mid + 1, e, l, r));
}
int root = -1;
//uso:
int arr[tam];
void solve(){
    int n, q;cin>>n>>q;
    for(int i = 0; i<n; i++){cin>>arr[i];
    update(root, 0, tam, i, Item(arr[i]));}
    while(q--){
        int l, r;cin>>l>>r;
        auto ans = query(root, 0, tam, l-1, r-1);
        cout<<ans.max_sum<<'\n';
    }
}
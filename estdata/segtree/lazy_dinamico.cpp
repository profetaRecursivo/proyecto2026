const ll INF = 4e18;
const int MAX_NODES = 7048237;

struct Info {
    ll sum;
    Info(ll s = 0) : sum(s) {}
};

struct Tag {
    ll add;
    Tag(ll a = 0) : add(a) {}
    bool has_lazy() const { return add != 0; }
};

Info merge_info(const Info& a, const Info& b) {
    return Info(a.sum + b.sum);
}

void apply_tag(Info& node_info, const Tag& tag, ll len) {
    node_info.sum += tag.add * len; 
}

void compose_tag(Tag& old_tag, const Tag& new_tag) {
    old_tag.add += new_tag.add;
}

struct Node {
    Info info;
    Tag tag;
    int left = -1;
    int right = -1;
} tree[MAX_NODES];

int nodes_cnt = 0;

int new_node() {
    int id = ++nodes_cnt;
    tree[id].left = -1;
    tree[id].right = -1;
    tree[id].info = Info();
    tree[id].tag = Tag();
    return id;
}

void clear_tree() { nodes_cnt = 0; }

void apply(int u, const Tag& t, ll len) {
    apply_tag(tree[u].info, t, len);
    compose_tag(tree[u].tag, t);
}

void push(int u, ll s, ll e) {
    if (!tree[u].tag.has_lazy()) return;
    ll mid = s + (e - s) / 2;
    if (tree[u].left == -1) tree[u].left = new_node();
    if (tree[u].right == -1) tree[u].right = new_node();
    apply(tree[u].left, tree[u].tag, mid - s + 1);
    apply(tree[u].right, tree[u].tag, e - mid);
    tree[u].tag = Tag(); 
}

void pull(int u) {
    Info l = (tree[u].left == -1) ? Info() : tree[tree[u].left].info;
    Info r = (tree[u].right == -1) ? Info() : tree[tree[u].right].info;
    tree[u].info = merge_info(l, r);
}

void update(int &u, ll s, ll e, ll l, ll r, const Tag& val) {
    if (u == -1) u = new_node();
    if (s >= l and e <= r) {
        apply(u, val, e - s + 1);
        return;
    }
    push(u, s, e);   
    ll mid = s + (e - s) / 2;
    if (mid >= l) update(tree[u].left, s, mid, l, r, val);
    if (mid < r)  update(tree[u].right, mid + 1, e, l, r, val);
    pull(u);
}
Info query(int u, ll s, ll e, ll l, ll r) {
    if (u == -1 or s > r or e < l) return Info(); 
    
    if (s >= l and e <= r) return tree[u].info;
    
    push(u, s, e);
    
    ll mid = s + (e - s) / 2;
    return merge_info(query(tree[u].left, s, mid, l, r),
                      query(tree[u].right, mid + 1, e, l, r));
}
int root = -1;
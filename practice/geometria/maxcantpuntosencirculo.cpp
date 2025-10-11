#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point { int x, y; };

struct Node {
    int x, y;
    int l = -1, r = -1;
    int minx, maxx, miny, maxy;
    int sz = 1;
};

vector<Point> pts;
vector<Node> tree;
int build(int l, int r, int depth) {
    if (l > r) return -1;
    int axis = depth & 1; // 0: x, 1: y
    int m = (l + r) >> 1;
    nth_element(pts.begin() + l, pts.begin() + m, pts.begin() + r + 1,
        [axis](const Point &a, const Point &b) {
            return axis == 0 ? a.x < b.x : a.y < b.y;
        });
    int idx = tree.size();
    tree.push_back(Node());
    tree[idx].x = pts[m].x;
    tree[idx].y = pts[m].y;
    tree[idx].minx = tree[idx].maxx = pts[m].x;
    tree[idx].miny = tree[idx].maxy = pts[m].y;
    tree[idx].sz = 1;
    tree[idx].l = build(l, m - 1, depth + 1);
    tree[idx].r = build(m + 1, r, depth + 1);

    auto upd_from_child = [&](int ch) {
        if (ch == -1) return;
        tree[idx].minx = min(tree[idx].minx, tree[ch].minx);
        tree[idx].maxx = max(tree[idx].maxx, tree[ch].maxx);
        tree[idx].miny = min(tree[idx].miny, tree[ch].miny);
        tree[idx].maxy = max(tree[idx].maxy, tree[ch].maxy);
        tree[idx].sz += tree[ch].sz;
    };
    upd_from_child(tree[idx].l);
    upd_from_child(tree[idx].r);
    return idx;
}

inline ll sq(ll x){ return x*x; }

ll minDistSqRect(int cx, int cy, const Node &nd){
    ll dx = 0;
    if (cx < nd.minx) dx = nd.minx - cx;
    else if (cx > nd.maxx) dx = cx - nd.maxx;
    ll dy = 0;
    if (cy < nd.miny) dy = nd.miny - cy;
    else if (cy > nd.maxy) dy = cy - nd.maxy;
    return dx*dx + dy*dy;
}
ll maxDistSqRect(int cx, int cy, const Node &nd){
    ll dx = max(llabs((ll)cx - nd.minx), llabs((ll)cx - nd.maxx));
    ll dy = max(llabs((ll)cy - nd.miny), llabs((ll)cy - nd.maxy));
    return dx*dx + dy*dy;
}

int queryKD(int node, int cx, int cy, ll r2){
    if (node == -1) return 0;
    const Node &nd = tree[node];
    if (minDistSqRect(cx, cy, nd) > r2) return 0; // fuera
    if (maxDistSqRect(cx, cy, nd) <= r2) return nd.sz; // todo dentro
    int ans = 0;
    if (sq((ll)nd.x - cx) + sq((ll)nd.y - cy) <= r2) ans++;
    ans += queryKD(nd.l, cx, cy, r2);
    ans += queryKD(nd.r, cx, cy, r2);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    if(!(cin >> N >> Q)) return 0;
    pts.resize(N);
    for(int i=0;i<N;i++) cin >> pts[i].x >> pts[i].y;
    tree.reserve(N);
    int root = build(0, N-1, 0);

    while(Q--){
        int cx, cy, r;
        cin >> cx >> cy >> r;
        ll r2 = ll(r) * ll(r);
        int ans = queryKD(root, cx, cy, r2);
        cout << ans << '\n';
    }
    return 0;
}
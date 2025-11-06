#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
const int tam = 1;
#define int long long

struct Node {
    int total_sum, prefix_sum, suffix_sum, max_sum, max_val;

    Node() : total_sum(0), prefix_sum(0), suffix_sum(0), max_sum(0), max_val(-100000000) {}
    Node(int val) : total_sum(val), prefix_sum(val), suffix_sum(val), max_sum(val), max_val(val){}
};

// Función para combinar dos nodos
static inline Node combine(const Node &left, const Node &right) {
    Node res;
    res.total_sum = left.total_sum + right.total_sum;
    res.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
    res.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
    res.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
    res.max_val = max(left.max_val, right.max_val);
    return res;
}

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    void build(const vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            return Node(INT_MIN); // Nodo neutro para max_sum
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left = query(2 * node + 1, start, mid, L, R);
        Node right = query(2 * node + 2, mid + 1, end, L, R);
        return combine(left, right);
    }

    void update(int node, int start, int end, int pos, int new_val) {
        if (start == end) {
            tree[node] = Node(new_val);
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(2 * node + 1, start, mid, pos, new_val);
            } else {
                update(2 * node + 2, mid + 1, end, pos, new_val);
            }
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    Node max_sum_query(int L, int R) {
        Node res = query(0, 0, n - 1, L, R);
        return res;
    }

    void update(int pos, int new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
    
};



void solve(){
   int n;scanf("%lld", &n);
   vector<int> arr(n);
   for(int i = 0; i<n; i++)scanf("%lld", &arr[i]);
   int q;scanf("%lld", &q);
   SegmentTree st(arr);
   while(q--){
    int a, b, c;scanf("%lld %lld %lld", &a, &b, &c);
    if(a){
        b--, c--;
        auto res = st.max_sum_query(b, c);
        if(res.max_sum == 0){
            printf("%lld\n", res.max_val);
        }else{
            printf("%lld\n", res.max_sum);
        }
    }else{
        b--;
        st.update(b, c);
    }
   }
}

signed main(){
   // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}
struct Node {
    int total_sum, max_sum, min_sum, prefix_sum, suffix_sum;
    Node() : total_sum(0), max_sum(INT_MIN), min_sum(INT_MAX), prefix_sum(0), suffix_sum(0) {}
};
 
class SegmentTree {
private:
    vector<Node> tree;
    int n;
 
    Node combine(const Node &left, const Node &right) {
        Node res;
        res.total_sum = left.total_sum + right.total_sum;
        res.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
        res.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
        res.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
        
        res.min_sum = min({left.min_sum, right.min_sum, left.suffix_sum + right.prefix_sum});
        return res;
    }
 
    void build(const vector<int> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].total_sum = arr[tl];
            tree[v].max_sum = arr[tl];
            tree[v].min_sum = arr[tl];
            tree[v].prefix_sum = arr[tl];
            tree[v].suffix_sum = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }
 
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return Node();
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        Node left_result = query(v * 2, tl, tm, l, min(r, tm));
        Node right_result = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(left_result, right_result);
    }
 
public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(n * 4);
        build(arr, 1, 0, n - 1);
    }
 
    int getMaxSum(int l, int r) {
        return query(1, 0, n - 1, l, r).max_sum;
    }
 
    int getMinSum(int l, int r) {
        return query(1, 0, n - 1, l, r).min_sum;
    }
};
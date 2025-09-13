// Mergesort Tree - Time <O(nlogn), O(log^2n)> - Memory O(nlogn)
// Mergesort Tree is a segment tree that stores the sorted subarray
// on each node.
vector<int> t[4*tam];
int arr[tam];
void build(int node, int b, int e) {
    if (b == e) { 
        t[node].pb(arr[b]); 
        return; 
    }
    int mid = (b + e) / 2;
    build(2*node, b, mid);
    build(2*node+1, mid+1, e);
    t[node].reserve(sz(t[2*node]) + sz(t[2*node+1]));
    merge(t[2*node].begin(), t[2*node].end(),
          t[2*node+1].begin(), t[2*node+1].end(),
          back_inserter(t[node]));
}
//query para saber el primer mayor o igual a x
//en un rango
int query(int node, int b, int e, int i, int j, int x){
    if(i<=b and e<=j){
        auto it = lower_bound(t[node].begin(), t[node].end(), x);
        if(it == t[node].end())
            return INF;
        return *it;
    }
    int mid = (b+e)/2, l = 2*node, r = 2*node+1;
    if(mid >= j)
        return query(l, b, mid, i, j, x);
    if(mid < i)
        return query(r, mid+1,e, i, j, x);
    return min(query(l, b, mid, i, j, x), query(r, mid+1,e, i, j, x));
}



int query(int node, int b, int e, int i, int j, int x, int y) {
  if (j < b || i > e) return 0;
  if (i <= b && j >= e)
    return upper_bound(t[node].begin(), t[node].end(), y) -
           lower_bound(t[node].begin(), t[node].end(), x);
  return query(2*node, b, (b+e)/2, i, j, x, y) +
         query(2*node+1, (b+e)/2+1, e, i, j, x, y);
}
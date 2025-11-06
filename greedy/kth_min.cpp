// What would be the k-th number in a[i ... j] segment, if this segment was sorted?
//nlog3n
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
        auto it = lower_bound(t[node].begin(), t[node].end(), x+1);
        return it - t[node].begin();
    }
    int mid = (b+e)/2, l = 2*node, r = 2*node+1;
    if(mid >= j)
        return query(l, b, mid, i, j, x);
    if(mid < i)
        return query(r, mid+1, e, i, j, x);
    return query(l, b, mid, i, j, x) + query(r, mid+1, e, i, j, x);
}
//que la query me diga cuantos son menores o iguales a x

unordered_map<int, int> mp;
void solve(){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> all;
    all.reserve(2*n);
    for(int i = 0; i<n; i++)scanf(" %d", &arr[i]);
    
    //sort(arr, arr+n);
    for(int i = 0; i<n; i++)
        all.push_back(arr[i]);
    
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    mp.reserve(sz(all));
    for(int i = 1; i<=sz(all); i++){
        mp[all[i-1]] = i;
    }
    int maxi = 0;
    for(int i = 0; i<n; i++){
        arr[i] = mp[arr[i]];
        maxi = max(maxi, arr[i]);
    }
    build(1, 0, n-1);
    for(int i = 0; i<q; i++){
        int l, r, k;
        scanf(" %d %d %d", &l, &r, &k);
        l--, r--;
        int left = 1, right = maxi;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            int res = query(1, 0, n-1, l, r, mid);
            if(res >= k){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }    
        printf("%d\n", all[ans-1]); 
    }
}

signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}
void solve(){
    int n; scanf("%d", &n);
    for(int i = 0; i<n; i++) scanf("%d", &arr[i]);
    int k; scanf("%d", &k);
    if (k <= 0) {
        printf("-1\n");
        return;
    }
    if (k > n) {
        printf("-1\n");
        return;
    }

    vector<int> tails;
    tails.reserve(min(n, k));

    for(int i = 0; i<n; i++){
        int x = arr[i];
        auto it = lower_bound(all(tails), x);
        if(it == tails.end()){
            tails.push_back(x);
        } else {
            *it = x;
        }
    }

    if ((int)tails.size() >= k) {
        printf("%d\n", tails[k-1]);
    } else {
        printf("-1\n");
    }
}
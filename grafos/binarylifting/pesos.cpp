for (int k = 1; k < LOG; k++){
    for (int u = 1; u <= n; u++) {
        int mid = up[u][k - 1];
        if (mid != 0/*centinela*/) {
            up[u][k] = up[mid][j - 1];
            sum_w[u][k] = sum_w[u][k - 1] + sum_w[mid][k - 1];
            min_w[u][k] = min(min_w[u][k - 1], min_w[mid][k - 1]);
        }
    }
}

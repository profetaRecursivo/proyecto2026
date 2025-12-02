struct inter_set {
    set<pair<int, int>> inter;
    void insertar(int left, int right) {
        auto it = inter.upper_bound({left, INF}); 
        if (it != inter.begin()) {
            it--;
            if (it->second < left) {
                it++;
            }
        }
        while (it != inter.end() and it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = inter.erase(it);
        }
        inter.insert({left, right});
    }
    bool contiene(int x) {
        auto it = inter.upper_bound({x, INF});
        if (it == inter.begin()) {
            return 0;
        }
        it--;
        return x <= it->second;
    }
    pair<int, int> contiene(int l, int r) {
        auto it = inter.upper_bound({l, INF});
        if (it == inter.begin()) {
            return {INF, INF};
        }
        it--;
        if (r <= it->second) {
            return *it;
        }
        return {INF, INF};
    }
};
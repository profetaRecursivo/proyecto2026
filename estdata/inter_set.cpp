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
    void erase(int l, int r) {
        if (l > r) return;
        auto it = inter.upper_bound({l, INF});
        if (it != inter.begin()) it--;
        vector<pair<int,int>> to_add;
        while (it != inter.end() and it->first <= r) {
            int a = it->first, b = it->second;
            if (b < l) {
                it++;
                continue;
            }
            auto it_erase = it++;
            inter.erase(it_erase);
            if (a < l) {
                to_add.emplace_back(a, l - 1);
            }
            if (b > r) {
                to_add.emplace_back(r + 1, b);
            }
        }
        for (auto &p : to_add) inter.insert(p);
    }
};
struct MinMaxDeque {
    struct Stack {
        struct Node { int v, mn, mx; };
        vector<Node> s;
        void push(int x) {
            int a = s.empty() ? x : min(x, s.back().mn);
            int b = s.empty() ? x : max(x, s.back().mx);
            s.push_back({x, a, b});
        }
        void pop() { s.pop_back(); }
        bool empty() { return s.empty(); }
        int top() { return s.back().v; }
        int mn() { return s.back().mn; }
        int mx() { return s.back().mx; }
        int size() { return s.size(); }
    } L, R;
    void rebalance() {
        vector<int> all, r;
        while (!L.empty()) { all.push_back(L.top()); L.pop(); }
        while (!R.empty()) { r.push_back(R.top()); R.pop(); }
        for (int i = (int)r.size() - 1; i >= 0; i--) all.push_back(r[i]);
        int m = (all.size() + 1) / 2;
        for (int i = m - 1; i >= 0; i--) L.push(all[i]);
        for (int i = m; i < (int)all.size(); i++) R.push(all[i]);
    }
    bool empty() { return L.empty() && R.empty(); }
    int size() { return L.size() + R.size(); }
    void push_front(int x) { L.push(x); }
    void push_back(int x) { R.push(x); }
    void pop_front() { if (L.empty()) rebalance(); L.pop(); }
    void pop_back() { if (R.empty()) rebalance(); R.pop(); }
    int front() { if (L.empty()) rebalance(); return L.top(); }
    int back() { if (R.empty()) rebalance(); return R.top(); }
    int getmin() {
        if (L.empty()) return R.mn();
        if (R.empty()) return L.mn();
        return min(L.mn(), R.mn());
    }
    int getmax() {
        if (L.empty()) return R.mx();
        if (R.empty()) return L.mx();
        return max(L.mx(), R.mx());
    }
};
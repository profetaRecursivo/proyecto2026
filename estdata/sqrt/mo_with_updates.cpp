
struct Mo {
    int n;
    vector<int> &a;
    vector<int> orig, last; 

    struct Query {
        int l, r, t, id;
    };

    struct Update {
        int idx;
        int prev, now; 
    };

    vector<Query> qs;
    vector<Update> up;

    int qcnt = 0;           
    int BLOCK;              
    int L, R, T;   

    ll current = 0; 

    Mo(vector<int> &arr) : n(sz(arr)), a(arr), orig(arr), last(arr) {
        BLOCK = max(1, (int)pow(n, 2.0/3.0));
    }

    void addQuery(int l, int r) {
        qs.push_back({l, r, (int)up.size(), qcnt++});
    }

    void addUpdate(int idx, int newVal) {
        int prevVal = last[idx];
        up.push_back({idx, prevVal, newVal});
        last[idx] = newVal;
    }

    inline void add(int idx) {
        current+=a[idx];
    }

    inline void remove(int idx) {
        current-=a[idx];
    }
    void applyUpdate(int k) {
        auto &u = up[k];
        int idx = u.idx;
        if (L <= idx && idx <= R) {
            remove(idx);
            a[idx] = u.now;
            add(idx);
        } else {
            a[idx] = u.now;
        }
    }

    void rollbackUpdate(int k) {
        auto &u = up[k];
        int idx = u.idx;
        if (L <= idx && idx <= R) {
            remove(idx);
            a[idx] = u.prev;
            add(idx);
        } else {
            a[idx] = u.prev;
        }
    }

    vector<ll> process() {
        if (qs.empty()) return {};
        a = orig;
        current = 0;
        L = 0;
        R = -1;
        T = 0;
        sort(qs.begin(), qs.end(), [&](const Query &x, const Query &y) {
            int bx = x.l / BLOCK;
            int by = y.l / BLOCK;
            if (bx != by) return bx < by;
            int brx = x.r / BLOCK;
            int bry = y.r / BLOCK;
            if (brx != bry) return brx < bry;
            return x.t < y.t;
        });

        vector<ll> ans(qcnt);

        for (auto &q : qs) {
            // mover tiempo
            while (T < q.t) {
                applyUpdate(T);
                ++T;
            }
            while (T > q.t) {
                --T;
                rollbackUpdate(T);
            }
            while (R < q.r) add(++R);
            while (L > q.l) add(--L);
            while (R > q.r) remove(R--);
            while (L < q.l) remove(L++);
            ans[q.id] = current;
        }
        return ans;
    }
};

vector<int> scs(string const& s) {
    int n = sz(s);
    int alph = 256;
    vector<int> p(n), c(n), cnt(max(alph, n), 0);
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < alph; i++) cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]]) classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];       
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev) ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suff_array(string s) {
    s += "$";
    vector<int> sort_shifts = scs(s);
    sort_shifts.erase(sort_shifts.begin());//eliminar el $
    return sort_shifts;
}
vector<int> lcp(string const& s, vector<int> const& p) {
    int n = sz(s);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) rank[p[i]] = i;   
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}//sufijo ^ patron
    auto cmp = [&](int pos, const string& pat) -> int {
        int i = 0;
        while (i < sz(pat) && i + pos < n) {
            if (s[i + pos] < pat[i]) return -1;
            if (s[i + pos] > pat[i]) return 1;
            i++;
        }
        if (i == sz(pat)) return 0;
        return -1; 
    };

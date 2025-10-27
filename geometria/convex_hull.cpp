
int orientation(pto a, pto b, pto c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pto a, pto b, pto c, bool colinear) {
    int o = orientation(a, b, c);
    return o < 0 or (colinear and o == 0);
}
bool ccw(pto a, pto b, pto c, bool colinear) {
    int o = orientation(a, b, c);
    return o > 0 or (colinear and o == 0);
}

vector<pto> ch(const vector<pto>& a, bool include_collinear = false) {
    vector<pto> ans = a;
    if (sz(ans) == 1)
        return ans;
    sort(ans.begin(), ans.end(), [](pto a, pto b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    // ans.erase(unique(ans.begin(), ans.end(), [](const pto &A, const pto &B){
    //     return A.x == B.x and A.y == B.y;
    // }), ans.end());
    pto p1 = ans[0], p2 = ans.back();
    vector<pto> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < sz(ans); i++) {
        if (i == sz(ans) - 1 or cw(p1, ans[i], p2, include_collinear)) {
            while (up.size() >= 2 and !cw(up[up.size()-2], up[up.size()-1], ans[i], include_collinear))
                up.pop_back();
            up.push_back(ans[i]);
        }
        if (i == sz(ans) - 1 or ccw(p1, ans[i], p2, include_collinear)) {
            while (down.size() >= 2 and !ccw(down[down.size()-2], down[down.size()-1], ans[i], include_collinear))
                down.pop_back();
            down.push_back(ans[i]);
        }
    }

    if (include_collinear and up.size() == sz(ans)) {
        reverse(ans.begin(), ans.end());
        return ans;
    }

    ans.clear();
    for (int i = 0; i < up.size(); i++)
        ans.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        ans.push_back(down[i]);

    ll area = 0;
    for (ll i = 0; i < sz(ans); i++) {
        pto cur = ans[i], nxt = ans[(i+1)%sz(ans)];
        area += (cur.x * nxt.y - nxt.x * cur.y);
    }
    if (area < 0) reverse(ans.begin(), ans.end());

    return ans;
}

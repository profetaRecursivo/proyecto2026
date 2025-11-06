#include <bits/stdc++.h>
using namespace std;
#define int long long
const double EPS = 1e-9;

struct pt {
    double x, y;
    pt() {}
    pt(double _x, double _y) : x(_x), y(_y) {}
    bool operator<(const pt& p) const {
        if (x < p.x - EPS) return true;
        if (fabs(x - p.x) < EPS && y < p.y - EPS) return true;
        return false;
    }
};

struct line {
    double a, b, c;
    line() {}
    line(const pt& p, const pt& q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }
    void norm() {
        double z = sqrt(a * a + b * b);
        if (z > EPS) { a /= z; b /= z; c /= z; }
    }
    double dist(const pt& p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d) { return a * d - b * c; }

inline bool intersect_1d(double a, double b, double c, double d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool betw(double l, double r, double x) {
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

bool intersectSegments(pt a, pt b, pt c, pt d, pt &left, pt &right) {
    // bounding box fast reject
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;

    line m(a, b), n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);

    if (fabs(zn) < EPS) { // parallel (or coincident)
        if (fabs(m.dist(c)) > EPS || fabs(n.dist(a)) > EPS)
            return false; // parallel but different lines

        // colinear -> intersection is overlap of projections
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);
        left = (c < a ? a : c);
        right = (b < d ? b : d);
        return true;
    } else {
        // unique intersection point of lines, check if inside segments
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        if (betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
            betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y))
            return true;
        return false;
    }
}

double fixZero(double x) { return (fabs(x) < 0.5e-9 ? 0.0 : x); }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    cout.setf(std::ios::fixed);
    cout<<setprecision(2);

    while (T--) {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pt a(x1,y1), b(x2,y2), c(x3,y3), d(x4,y4);
        pt L, R;
        bool ok = intersectSegments(a,b,c,d,L,R);
        if (!ok) {
            cout << "none\n";
            continue;
        }
        // if intersection is a single point
        if (fabs(L.x - R.x) < EPS && fabs(L.y - R.y) < EPS) {
            cout << fixZero(L.x) << ' ' << fixZero(L.y) << '\n';
        } else {
            // ensure ordering: point with smallest x (or y if tie) first
            if (R < L) swap(L, R);
            cout << fixZero(L.x) << ' ' << fixZero(L.y) << ' '
                 << fixZero(R.x) << ' ' << fixZero(R.y) << '\n';
        }
    }
    return 0;
}

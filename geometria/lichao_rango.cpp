struct Line {
    ll a, b;
    Line(ll _a=0, ll _b=-INF) : a(_a), b(_b) {}
    ll eval(ll x) const { return a*x + b; }
};

struct LiChao {
    ll l, r;
    Line line;
    unique_ptr<LiChao> left, right;
    LiChao(ll _l, ll _r) : l(_l), r(_r), line(Line()), left(nullptr), right(nullptr) {}
    void insert(Line nueva, ll L_, ll R_) {
        if (R_ < l || r < L_) return;
        if (L_ <= l && r <= R_) {
            ll m = (l + r) >> 1;
            bool leftBetter = nueva.eval(l) > line.eval(l);
            bool midBetter  = nueva.eval(m) > line.eval(m);

            if (midBetter) swap(line, nueva);

            if (l == r) return;

            if (leftBetter != midBetter) {
                if (!left) left = make_unique<LiChao>(l, m);
                left->insert(nueva, L_, R_);
            } else {
                if (!right) right = make_unique<LiChao>(m+1, r);
                right->insert(nueva, L_, R_);
            }
            return;
        }
        ll m = (l + r) >> 1;
        if (L_ <= m) {
            if (!left) left = make_unique<LiChao>(l, m);
            left->insert(nueva, L_, R_);
        }
        if (R_ > m) {
            if (!right) right = make_unique<LiChao>(m+1, r);
            right->insert(nueva, L_, R_);
        }
    }
    ll query(ll x) const {
        ll res = line.eval(x);
        if (l == r) return res;
        ll m = (l + r) >> 1;
        if (x <= m) {
            if (left) res = max(res, left->query(x));
        } else {
            if (right) res = max(res, right->query(x));
        }
        return res;
    }
};



//para minimos
struct Line {
    ll a, b;
    Line(ll _a=0, ll _b=INF) : a(_a), b(_b) {} // INF en vez de -INF
    ll eval(ll x) const { return a*x + b; }
};

struct LiChao {
    ll l, r;
    Line line;
    unique_ptr<LiChao> left, right;
    LiChao(ll _l, ll _r) : l(_l), r(_r), line(Line()), left(nullptr), right(nullptr) {}
    void insert(Line nueva, ll L_, ll R_) {
        if (R_ < l || r < L_) return;
        if (L_ <= l && r <= R_) {
            ll m = (l + r) >> 1;
            bool leftBetter = nueva.eval(l) < line.eval(l); // < para mínimos
            bool midBetter  = nueva.eval(m) < line.eval(m); // < para mínimos

            if (midBetter) swap(line, nueva);

            if (l == r) return;

            if (leftBetter != midBetter) {
                if (!left) left = make_unique<LiChao>(l, m);
                left->insert(nueva, L_, R_);
            } else {
                if (!right) right = make_unique<LiChao>(m+1, r);
                right->insert(nueva, L_, R_);
            }
            return;
        }
        ll m = (l + r) >> 1;
        if (L_ <= m) {
            if (!left) left = make_unique<LiChao>(l, m);
            left->insert(nueva, L_, R_);
        }
        if (R_ > m) {
            if (!right) right = make_unique<LiChao>(m+1, r);
            right->insert(nueva, L_, R_);
        }
    }
    ll query(ll x) const {
        ll res = line.eval(x);
        if (l == r) return res;
        ll m = (l + r) >> 1;
        if (x <= m) {
            if (left) res = min(res, left->query(x)); // min en vez de max
        } else {
            if (right) res = min(res, right->query(x)); // min en vez de max
        }
        return res;
    }
};



// con doubles
struct Line {
    double a, b;
    Line(double _a=0, double _b=-1e100) : a(_a), b(_b) {}
    double eval(double x) const { return a*x + b; }
};

struct LiChao {
    double l, r;
    Line line;
    unique_ptr<LiChao> left, right;
    static double eps; // <-- eps global de la clase
    LiChao(double _l, double _r) : l(_l), r(_r), line(Line()), left(nullptr), right(nullptr) {}

    void insert(Line nueva, double L_, double R_) {
        if (R_ + eps < l || r + eps < L_) return;
        if (L_ <= l + eps && r <= R_ + eps) {
            double m = (l + r) / 2.0;
            bool leftBetter = nueva.eval(l) > line.eval(l) + eps;
            bool midBetter  = nueva.eval(m) > line.eval(m) + eps;

            if (midBetter) swap(line, nueva);

            if (fabs(l - r) < eps) return; // hoja

            if (leftBetter != midBetter) {
                if (!left) left = make_unique<LiChao>(l, m);
                left->insert(nueva, L_, R_);
            } else {
                if (!right) right = make_unique<LiChao>(m, r);
                right->insert(nueva, L_, R_);
            }
            return;
        }
        double m = (l + r) / 2.0;
        if (L_ <= m + eps) {
            if (!left) left = make_unique<LiChao>(l, m);
            left->insert(nueva, L_, R_);
        }
        if (R_ > m - eps) {
            if (!right) right = make_unique<LiChao>(m, r);
            right->insert(nueva, L_, R_);
        }
    }

    double query(double x) const {
        double res = line.eval(x);
        if (fabs(l - r) < eps) return res;
        double m = (l + r) / 2.0;
        if (x <= m + eps) {
            if (left) res = max(res, left->query(x));
        } else {
            if (right) res = max(res, right->query(x));
        }
        return res;
    }
};

// Inicializar eps fuera de la clase
double LiChao::eps = 1e-9; // <-- puedes cambiarlo donde quieras

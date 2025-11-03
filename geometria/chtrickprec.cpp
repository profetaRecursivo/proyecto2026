struct Line {
    mutable double k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(double x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    const double INF = 1e300;
    const double EPS = 1e-12;
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = INF; return false; }
        // tratar pendientes casi iguales como iguales
        if (fabs(x->k - y->k) < EPS) {
            // la que tenga mayor m domina para máximos
            x->p = (x->m > y->m ? INF : -INF);
        } else {
            x->p = (y->m - x->m) / (x->k - y->k);
        }
        return x->p > y->p - EPS;
    }
    void add(double k, double m) {
        auto z = insert({k, m, 0.0}), y = z++, x = y;
        // eliminar siguientes dominadas
        while (isect(y, z)) z = erase(z);
        // comprobar la anterior
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        // limpiar hacia atrás usando EPS
        while ((y = x) != begin() && (--x)->p > y->p - EPS)
            isect(x, erase(y));
    }
    double query(double x) {
        assert(!empty());
        auto l = *lower_bound(x); // usa operator<(double)
        return l.k * x + l.m;
    }
};

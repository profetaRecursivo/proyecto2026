struct LineContainer : multiset<Line, less<>> {
    const double EPS = 1e-12;
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = 1e18; return false; }
        if (x->k == y->k) x->p = (x->m > y->m ? 1e18 : -1e18);
        else x->p = (y->m - x->m) / (x->k - y->k);
        return x->p >= y->p;
        //double return x->p > y->p - EPS;
    }
    //si hay un epsilon

    void add(double k, double m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    double query(double x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

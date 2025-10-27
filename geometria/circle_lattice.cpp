ll lattice_circle2(ld h, ld k, ld r) {
    // cuenta puntos (x,y) enteros tales que r <= sqrt((x-h)^2 + (y-k)^2) < r+1
    ll cnt = 0;
    ll x_min = (ll)ceil(h - (r + 1.0L) - EPS);
    ll x_max = (ll)floor(h + (r + 1.0L) + EPS);
    for (ll x = x_min; x <= x_max; ++x) {
        ld dx = (ld)x - h;
        ld A = r*r - dx*dx;                 
        ld B = (r+1.0L)*(r+1.0L) - dx*dx;  
        if (B <= 0.0L) continue;           
        ld sqrtA = (A <= 0.0L ? 0.0L : sqrtl(A));
        ld sqrtB = sqrt(B);
        ll Ylo = (ll)ceill(k - sqrtB + EPS);   
        ll Yhi = (ll)floorl(k + sqrtB - EPS);
        if (Yhi < Ylo) continue;
        ll total_candidates = Yhi - Ylo + 1;

        ll inside = 0;
        if (A > 0.0L) {
            // y en (k - sqrtA, k + sqrtA) (estricto)
            ll Ilo = (ll)ceill(k - sqrtA + EPS);
            ll Ihi = (ll)floorl(k + sqrtA - EPS);
            if (Ihi >= Ilo) inside = Ihi - Ilo + 1;
        }
        cnt += (total_candidates - inside);
    }
    return cnt;
}


ll lattice_circle1(ld h, ld k, ld r) {
    //que cuenta?
    // Cuenta lattice points (x,y) enteros con sqrt((x-h)^2+(y-k)^2) <= r (dentro o en el borde), O(r).
    ll cnt = 0;
    ll x_min = (ll)ceil(h - r - EPS);
    ll x_max = (ll)floor(h + r + EPS);
    for (ll x = x_min; x <= x_max; ++x) {
        ld dx = (ld)x - h;
        ld delta = r*r - dx*dx;
        if (delta < -EPS) continue;
        if (delta < 0) delta = 0;
        ld dy = sqrt(delta);
        ll y_min = (ll)ceil(k - dy - EPS);
        ll y_max = (ll)floor(k + dy + EPS);
        if (y_max >= y_min) cnt += (y_max - y_min + 1);
    }
    return cnt;
}
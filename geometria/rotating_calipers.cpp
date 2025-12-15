ll cross(const pto& a, const pto& b, const pto& c) { 
    return (b - a) % (c - a); 
}
//maxima distancia entre dos puntos de un polygono convexo
ll rc(const vector<pto>& hull) {
	int j = 1;
	ll max_dist2 = 0;
	pto p1 = hull[0];
	pto p2 = hull[1];
	int n = sz(hull);
	for (int i = 0; i < n; i++) {
		while (1) {
			int ni = (i + 1) % n;
			int nj = (j + 1) % n;
			if (cross(hull[i], hull[ni], hull[nj]) >
				cross(hull[i], hull[ni], hull[j])) {
				j = nj;
			} else
				break;
		}

		auto diff = hull[i] - hull[j];
		ll dist2 = diff.dist2();
		if (dist2 > max_dist2) {
			max_dist2 = dist2;
			p1 = hull[i];
			p2 = hull[j];
		}
	}
	return max_dist2;
}

//minima distancia entre dos polygonos
ll rc(const vector<Punto>& poly1, const vector<Punto>& poly2) {
    int n = sz(poly1), m = sz(poly2);
    ll min_dist = INF;
    int i = 0, j = 0;
    for (int k = 0; k < n; k++) {
        while (cross(poly1[i], poly2[j], poly2[(j + 1) % m]) > 0) {
            j = (j + 1) % m;
        }
        ll dist = (poly1[i] - poly2[j]).dist2();
        min_dist = min(min_dist, dist);
        i = (i + 1) % n;
    }
    return min_dist;
}
ll cross(const pto& a, const pto& b, const pto& c) { 
    return (b - a) % (c - a); 
}

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
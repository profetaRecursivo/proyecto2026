int x, y, d;

void extEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extEuclid(b, a % b);
	x = x - (a / b) * y;
	swap(x, y);
}

int solve(int a, int b, int c, int x1, int x2, int y1, int y2) {
	extEuclid(a, b);
	if (!a && !b) {
		if (c) return 0;
		return (x2 - x1 + 1) * (int)(y2 - y1 + 1);
	}
	else if (!a) {
		if (c % b) return 0;
		c = -c / b;
		if (y1 <= c && c <= y2) return (x2 - x1 + 1);
		return 0;
	}
	else if (!b) {
		if (c % a) return 0;
		c = -c / a;
		if (x1 <= c && c <= x2) return (y2 - y1 + 1);
		return 0;
	}
	if (c % d == 0) {
		x *= (-c / d); y *= (-c / d);
		b /= d; a /= d;
		swap(a, b);
		double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
		if (p > q) swap(p, q);
		x1 = (int)ceil(p);
		x2 = (int)floor(q);
		p = (y - y1) / (double)b; q = (y - y2) / (double)b;
		if (p > q) swap(p, q);
		y1 = (int)ceil(p);
		y2 = (int)floor(q);
		x1 = max(x1, y1); x2 = min(x2, y2);
		return max(0LL, x2 - x1 + 1);
	}
	return 0;
}
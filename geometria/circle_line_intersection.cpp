vector<pair<ld, ld>> circle_line_inter(ld r, ld a, ld b, ld c, ld h, ld k) {
    vector<pair<ld, ld>> ans;
	ld c_new = c + a * h + b * k;  // ajustar c para el nuevo centro
	ld x0 = -a * c_new / (a * a + b * b), y0 = -b * c_new / (a * a + b * b);
	if (c_new * c_new > r * r * (a * a + b * b) + EPS)

	else if (abs(c_new * c_new - r * r * (a * a + b * b)) < EPS) {
        ans.push_back({x0 + h, y0 + k})
	} else {
		ld d = r * r - c_new * c_new / (a * a + b * b);
		ld mult = sqrt(d / (a * a + b * b));
		ld ax = x0 + b * mult + h;
		ld bx = x0 - b * mult + h;
		ld ay = y0 - a * mult + k;
		ld by = y0 + a * mult + k;
        ans.push_back({ax, ay});
        ans.push_back({bx, by});
	}
    return ans;
}
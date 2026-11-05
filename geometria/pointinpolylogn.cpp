bool enSegmento(pto a, pto b, pto p) {
    return ((p - a) * (b - a) >= 0) && ((p - b) * (a - b) >= 0);
}

int puntoEnPoligonoConvexo(const vector<pto>& poly, const pto& p) {
    int n = poly.size();
    pto o = poly[0];
    int cp1 = (poly[1] - o) % (p - o);
    if (cp1 == 0) {
        return enSegmento(o, poly[1], p) ? 0 : -1;
    }
    int cpn = (poly[n - 1] - o) % (p - o);
    if (cpn == 0) {
        return enSegmento(o, poly[n - 1], p) ? 0 : -1;
    }
    if (cp1 < 0 or cpn > 0) return -1;
    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ((poly[mid] - o) % (p - o) >= 0) l = mid;
        else r = mid;
    }
    int side = (poly[l + 1] - poly[l]) % (p - poly[l]);
    if (side > 0) return 1;   // IN
    if (side == 0) return 0;  // ON
    return -1;               // OUT
}

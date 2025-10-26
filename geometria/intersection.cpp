bool intersectan(punto a, punto b, punto c, punto d) {
    punto ab = b - a;
    punto cd = d - c;
    int s1 = signo(ab % (c - a));
    int s2 = signo(ab % (d - a));
    int s3 = signo(cd % (a - c));
    int s4 = signo(cd % (b - c));
    if (s1 == 0 and s2 == 0 and s3 == 0 and s4 == 0) {
        // revisar proyección 1D
        if (max(a.x, b.x) < min(c.x, d.x) or max(c.x, d.x) < min(a.x, b.x)) return 0;
        if (max(a.y, b.y) < min(c.y, d.y) or max(c.y, d.y) < min(a.y, b.y)) return 0;
        return 1;
    }
    return s1 * s2 <= 0 and s3 * s4 <= 0;
}
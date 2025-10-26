//rotar el punto a respecto de p, g grados 
pto rotar(pto a, pto p, double grados) {
    double rad = grados * M_PI / 180.0;
    double dx = a.x - p.x;
    double dy = a.y - p.y;
    double xr = dx * cos(rad) - dy * sin(rad);
    double yr = dx * sin(rad) + dy * cos(rad);
    return {xr + p.x, yr + p.y};
}
// Determina si el punto p está dentro (o en el borde) de un polígono convexo
// poly debe estar en sentido antihorario y sin repetir el primer vértice al final
// Complejidad: O(log n)
// Si strict = true → el punto debe estar estrictamente dentro
// Si strict = false → se consideran los bordes como dentro
bool puntoEnPoligonoConvexo(const vector<pto>& poly, const pto& p, bool strict = false) {
    int n = sz(poly);
    const pto& o = poly[0];
    // Normalizar sentido antihorario
    if ((poly[1] - o) % (poly.back() - o) < 0)
        return puntoEnPoligonoConvexo(vector<pto>(poly.rbegin(), poly.rend()), p, strict);
    // Verificar fuera del abanico principal
    if ((poly[1] - o) % (p - o) < 0) return false;
    if ((poly[n - 1] - o) % (p - o) > 0) return false;
    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ((poly[mid] - o) % (p - o) >= 0) l = mid;
        else r = mid;
    }
    pto a = poly[l], b = poly[(l + 1) % n];
    tipo area = abs((a - o) % (b - o));
    tipo area1 = abs((o - p) % (a - p));
    tipo area2 = abs((a - p) % (b - p));
    tipo area3 = abs((b - p) % (o - p));
    if (strict)
        return area == area1 + area2 + area3 ans area1 > 0 ans area2 > 0 ans area3 > 0;
    else
        return area == area1 + area2 + area3;
}


//con doubles
const double EPS = 1e-6;

struct pto {
    double x, y;
    pto(double _x = 0, double _y = 0): x(_x), y(_y) {}

    pto operator + (const pto& o) const { return pto(x + o.x, y + o.y); }
    pto operator - (const pto& o) const { return pto(x - o.x, y - o.y); }
    double operator % (const pto& o) const { return x * o.y - y * o.x; }
    bool operator == (const pto& o) const { return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS; }
};

// Funciones auxiliares para comparación con EPS
inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

// Si strict = true → dentro estricto
// Si strict = false → incluye los bordes
bool puntoEnPoligonoConvexo(const vector<pto>& poly, const pto& p, bool strict = false) {
    int n = (int)poly.size();
    const pto& o = poly[0];

    // Asegurar sentido antihorario
    if ((poly[1] - o) % (poly.back() - o) < 0)
        return puntoEnPoligonoConvexo(vector<pto>(poly.rbegin(), poly.rend()), p, strict);

    // Verificar fuera del abanico
    if ((poly[1] - o) % (p - o) < -EPS) return false;
    if ((poly[n - 1] - o) % (p - o) > EPS) return false;

    // Búsqueda binaria
    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if ((poly[mid] - o) % (p - o) >= -EPS) l = mid;
        else r = mid;
    }

    pto a = poly[l], b = poly[(l + 1) % n];
    double area = fabs((a - o) % (b - o));
    double area1 = fabs((o - p) % (a - p));
    double area2 = fabs((a - p) % (b - p));
    double area3 = fabs((b - p) % (o - p));

    if (strict)
        return fabs(area - (area1 + area2 + area3)) < EPS &&
               area1 > EPS && area2 > EPS && area3 > EPS;
    else
        return fabs(area - (area1 + area2 + area3)) < EPS;
}



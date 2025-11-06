// Devuelve true si el polígono está en sentido antihorario (CCW)
// y false si está en sentido horario (CW)
bool esCCW(const vector<pto>& poly) {
    double area = 0;
    int n = (int)poly.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (poly[j] - poly[i]) % poly[i]; // equivalente a (x_i*y_{i+1} - y_i*x_{i+1})
    }
    return area > EPS; // positivo → CCW
}

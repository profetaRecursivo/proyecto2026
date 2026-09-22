struct line {
  int a, b, c;
  line(pto p, pto q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    normalize();
  };
  void setOrigin(pto p) { c += a * p.x + b * p.y; } //trasladar linea como si p fuera el origen
  void normalize() {
    int g = gcd(abs(a), gcd(abs(b), abs(c)));
    if (g > 0) {
        a /= g;
        b /= g;
        c /= g;
    }
    if (a < 0 or (a == 0 and b < 0) or (a == 0 and b == 0 and c < 0)) {
        a = -a;b = -b;c = -c;
    }
  }//normalizamos para poder comprar la igualdad de dos lineas
};

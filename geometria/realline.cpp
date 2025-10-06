struct real_line {
  long double a, b, c;
  line(pto p, pto q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    normalize();
  };
  void setOrigin(pto p) { c += a * p.x + b * p.y; } //trasladar linea como si p fuera el origen
  void normalize(){
    long double z = sqrtl(a*a + b*b);
    a/=z, b/=z, c/=z;
  }
  bool operator==(const real_line& otro) const {
    const long double EPS = 1e-9;
    return fabsl(a - otro.a) < EPS &&
           fabsl(b - otro.b) < EPS &&
           fabsl(c - otro.c) < EPS;
  }

};
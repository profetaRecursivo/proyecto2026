struct line {
  int a, b, c;
  line(pto p, pto q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    normalize();
  };
  void setOrigin(pto p) { c += a * p.x + b * p.y; } //trasladar linea como si p fuera el origen
  void normalize(){
    int g = gcd(abs(a), gcd(abs(b), abs(c)));
    a/=g;
    b/=g;
    c/=g;
    if(a < 0 or (a == 0 and b < 0))
        a*=-1, b*=-1, c*=-1;
  }//normalizamos para poder comprar la igualdad de dos lineas
  const bool operator==(const line& otro) const {
    return a == otro.a and b == otro.b and c == otro.c;
  }

};
//si el determinante entre dos lineas es cero, son paralelas, pracicamente un prod cruz
double det(double a, double b, double c, double d) {
	return a * d - b * c;
}
pto intersec(line a, line b) { //primero estar seguro si no son paralelas
	double d = -det(a.a, a.b, b.a, b.b);
	return pto(det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d);
}
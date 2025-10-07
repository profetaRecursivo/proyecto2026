bool ge(double x, double y) { return x + EPS > y; }
bool le(double x, double y) { return x - EPS < y; }
bool eq(double x, double y) { return ge(x, y) and le(x, y); }
int sign(double x) { return ge(x, 0) - le(x, 0); }
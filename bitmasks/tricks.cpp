//generacion de mascaras lexicograficas
unsigned int nextComb(unsigned int x) {
    unsigned int c = x & -x;
    unsigned int r = x + c;
    return (((r ^ x) >> 2) / c) | r;
}
//redondear hacia arriba
unsigned int nextPow2(unsigned int x) {
    if (x == 0) return 1;
    return 1u << (32 - __builtin_clz(x - 1));
}
//redondear hacia abajo
unsigned int prevPow2(unsigned int x) {
    return 1u << (31 - __builtin_clz(x));
}

//generacion de mascaras lexicograficas
unsigned int nextComb(unsigned int x) {
    unsigned int c = x & -x;
    unsigned int r = x + c;
    return (((r ^ x) >> 2) / c) | r;
}
int n = 5; // Queremos usar solo los primeros 5 bits (posiciones 0 a 4)
int k = 3; // Tomando de 3 en 3
unsigned int mask = (1U << k) - 1; // 00111 (3 bits en 1)
while (mask < (1U << n)) {
    // 1. Usar 'mask' aquí
    // 2. Avanzar a la siguiente combinación
    mask = nextComb(mask);
}
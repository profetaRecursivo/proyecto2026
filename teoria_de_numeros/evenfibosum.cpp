int sumaFibonacciPar(int limite) {
    int a = 0, b = 2;
    int suma = a + b;
    while (true) {
        int siguiente = 4 * b + a;
        if (siguiente > limite) break;
        suma += siguiente;
        a = b;
        b = siguiente;
    }
    return suma;
}
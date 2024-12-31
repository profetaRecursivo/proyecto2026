bool perfectsquare(__int128_t x) {
    if (x < 0) return false;
    __int128_t raiz = sqrt((long double)x);
    return raiz * raiz == x;
}

string isFibo(long long n) {
    __int128_t a = 5;
    a *= n;
    a *= n;
    __int128_t b = a - 4;
    a += 4;
    return perfectsquare(a) or perfectsquare(b);
}
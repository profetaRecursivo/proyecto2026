//el mayor exponente de p que divide a n!
int multiplicidad(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}
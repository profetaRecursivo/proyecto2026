int gecd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gecd(a, b) * b;
}
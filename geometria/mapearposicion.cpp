int mapear(int fil, int col, int m) {
    return fil * m + col;
}

pair<int, int> desmapear(int val, int m) {
    int row = val / m;
    int col = val % m;
    return {row, col};
}

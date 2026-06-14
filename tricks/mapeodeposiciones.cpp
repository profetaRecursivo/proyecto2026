// INDEXADO A 0

int f(int i, int j, int m) {
    return i * m + j;
}

pair<int,int> g(int id, int m) {
    return {id / m, id % m};
}

// INDEXADO A 1

int f1(int i, int j, int m) {
    return (i - 1) * m + j;
}

pair<int,int> g1(int id, int m) {
    return {(id - 1) / m + 1, (id - 1) % m + 1};
}

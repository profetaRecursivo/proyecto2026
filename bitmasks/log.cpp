int log2int(unsigned int x) {
    return 31 - __builtin_clz(x);
}
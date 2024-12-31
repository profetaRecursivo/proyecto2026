//un poco mas eficiente en cache
//no accesa ranto a la memoria
//espri[i] == 0 entonces i es primo
const int N = 1001;
bitset<N> espri;
void sieve(){
    espri[0] = espri[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (!espri[i]) {
            for (int j = i * i; j <N; j += i)
                espri[j] = true;
        }
    }
}
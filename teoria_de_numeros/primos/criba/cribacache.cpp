//un poco mas eficiente en cache
//no accesa ranto a la memoria
//espri[i] == 0 entonces i es primo
const int N = 1001;
vector<bool> espri(N+1, true);
void sieve(){
    espri[0] = espri[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (espri[i]) {
            for (int j = i * i; j <N; j += i)
                espri[j] = false;
        }
    }
}
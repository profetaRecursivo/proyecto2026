//un poco mas eficiente en cache
//no accesa ranto a la memoria
//espri[i] == 0 entonces i es primo
vector<bool> espri(tam+1, true);
void sieve(){
    espri[0] = espri[1] = false;
    for (int i = 2; i * i < tam; i++) {
        if (espri[i]) {
            for (int j = i * i; j <tam; j += i)
                espri[j] = false;
        }
    }
}
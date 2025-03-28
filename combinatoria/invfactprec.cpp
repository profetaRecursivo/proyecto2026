ll fact[tam+2], invFact[tam+2];
void prec(){
    fact[0] = 1;
    fore(i, 1, tam){
        fact[i] = i*fact[i-1];
        invFact[i] = expmod(fact[i], MOD-2, MOD);
    }
}
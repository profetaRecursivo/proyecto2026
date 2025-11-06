const int tam = 61;
ll basis[tam] = {0};
ll ans  = 0;
void insert(ll x){
    for(int i = tam-1; i>=0; i--){
        if(x&(1LL<<i)){
            if(!basis[i]){
                basis[i] = x;
                ans++;
                return;
            }
            x^=basis[i];
        }
    }
}
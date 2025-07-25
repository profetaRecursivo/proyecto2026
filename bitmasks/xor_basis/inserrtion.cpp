void insert(ll x){
    for(int i = tam-1; i>=0; i--){
        if(x&(1LL<<i)){
            if(!basis[i]){
                basis[i] = x;
                return;
            }
            x^=basis[i];
        }
    }
}
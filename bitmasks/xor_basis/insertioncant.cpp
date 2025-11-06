// // // You are given an empty sequence a
// . Your task is to process q
//  queries of the following types:
// 1. Append x
//  to the end of sequence a
// 2. Consider all 2k
//  possible subsequences of a
// , where k
//  represents the current length of a
// . Among these subsequences, determine how many have a bitwise XOR value equal to x
// . Output the result modulo 998244353
int basis[tam] = {0};
ll expmod(ll a, ll b,ll  m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void insert(int x){
    for(int i = tam-1; i>=0; i--){
        if(x&(1LL<<i)){
            if(!basis[i]){
                basis[i] = x;
                sz++;
                return;
            }
            x^=basis[i];
        }
    }
}
void solve(){
    int n;cin>>n;
    int cant = 0;
    for(int _ = 0; _<n; _++){
        int t, q;cin>>t>>q;
        if(t == 1){
            insert(q);
            cant++;
        }else{
            for(int i = tam-1; i>=0; i--){
                if(q&(1LL<<i)){
                    q^=basis[i];
                }
            }
            if(q){
                cout<<"0\n";
            }else{
                cout<<expmod(2, cant - sz, MOD)<<endl;
            }
        }
    }
}
//https://www.spoj.com/problems/BSPRIME/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
//const int INF = 1e18;
const int tam = 150000000;
bitset<tam> bs;
int posicion(int n) {
    return 31 - __builtin_clz(n);
}
#define sz(x) (int)(x).size()
vector<int> primos;
void sqsieve(int n) {
    const int S = 100000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> esprimo(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (esprimo[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                esprimo[j] = false;
        }
    }
    
    vector<char> block(S);

    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int posini = (start + p - 1) / p;
            for (int j = max(posini, p) * p - start; j < S; j += p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;

        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                primos.push_back(start + i);
        }
    }
}
vector<int> prefix(tam+1, 0);
void init(){
    sqsieve(105000000);
    cout<<"si se pudo\n";
    int pointer = 0;
    int pointerprimo = 0;
    int pos = posicion(primos[pointerprimo]);
    while(pointer < tam){
        if(pos < 0){
            pointerprimo++;
            pos = posicion(primos[pointerprimo]);
        }
        bs[pointer++] = (1<<(pos) & primos[pointerprimo] != 0);
        pos--;
    }
    
}
void solve(){
    init();
}
signed main(){
   // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)solve();
}
#include <iostream>
using namespace std;

int sumaFibonacciPar(int limite) {
    int a = 0, b = 2;
    int suma = a + b;
    while (true) {
        int siguiente = 4 * b + a;
        if (siguiente > limite) break;
        suma += siguiente;
        a = b;
        b = siguiente;
    }
    return suma;
}
void solve(){
    int n;cin>>n;
    cout<<sumaFibonacciPar(n)<<endl;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

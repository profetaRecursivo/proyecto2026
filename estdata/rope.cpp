/*
Operación               Complejidad        Descripción
---------------------------------------------------------------
insert(pos, s)          O(log n)           Inserta una subsecuencia en la posición `pos`
erase(pos, len)         O(log n)           Elimina un fragmento de longitud `len` desde `pos`
replace(pos, len, s)    O(log n)           Reemplaza un fragmento por otra subsecuencia
substr(pos, len)        O(log n + len)     Extrae una subsecuencia (subrope) desde `pos`
operator[]              O(log n)           Accede al i-ésimo elemento
+= / append             O(log n)           Concatena eficientemente al final
report(start, end)      O(log n + len)     Similar a substr, útil para debugging o extracción
*/
#include <ext/rope>
#include <bits/stdc++.h>
using namespace __gnu_cxx;
using namespace std;

signed main(){
    int n;cin>>n;
    rope<int> rp;
    for(int i = 0; i<n; i++){
        int x;cin>>x;
        rp.push_back(x);
    }
    //ineficiente para 10^5*18
    //funciona mejor con subcadenas
    for(int i = 0; i<n;i ++){
        int pos;cin>>pos;
        cout<<rp[pos-1]<<" ";
        rp.erase(pos-1, 1);
    }
}
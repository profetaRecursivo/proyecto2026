#include <bits/stdc++.h>
using namespace std;
//PLUS ULTRA RECARGADO!!!


/*
En C++, goto no puede saltar a un punto 
donde se encuentre una variable o 
código de inicialización que no haya sido 
ejecutado aún. El problema radica en el 
orden de ejecución y 
las reglas de alcance de las variables.*/

void solve() {
    //Para usar el goto se usan etiquetas
    if(true)
        goto etiqueta;
    //int x = 5;
    etiqueta:
    cout<<213123<<endl;
}
signed main() {
    
}
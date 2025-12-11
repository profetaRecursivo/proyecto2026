#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

struct Nodo{
    bool esfinal;
    int cant;
    Nodo* hijos[26];

    Nodo(){
        esfinal = false;
        cant = 0;
        for(int i = 0; i<26; i++){
            hijos[i] = nullptr;
        }
    }
};
Nodo* root;

void insertar(string& s){
    Nodo* actual = root;
    for(int i = 0; i<sz(s); i++){
        int pos = s[i] - 'a';
        if(actual->hijos[pos] == nullptr){
            actual->hijos[pos] = new Nodo();
        }
        actual->hijos[pos]->cant++;
        actual = actual->hijos[pos];
    }
    actual->esfinal = true;
}

int buscar(string& pref){
    Nodo* actual = root;
    for(int i = 0; i<sz(pref); i++){
        int pos = pref[i] - 'a';
        if(actual->hijos[pos] != nullptr){
            actual = actual->hijos[pos];
        }else{
            return 0;
        }
    }
    return actual->cant;
}

void eliminar(string& s, int i, Nodo* actual){
    if(i < sz(s)){
        int pos = s[i] - 'a';
        eliminar(s, i+1, actual->hijos[pos]);
        actual->hijos[pos]->cant--;
        if(actual->hijos[pos]->cant == 0){
            //eliminamos
            actual->hijos[pos] = nullptr;
        }
    }
}

void solve(){
    root = new Nodo();
    int n;cin>>n;
    for(int i = 0; i<n; i++){
        string s;cin>>s;
        insertar(s);
    }
    int q;cin>>q;
    while(q--){
        string pref;cin>>pref;
        cout<<buscar(pref)<<'\n';
    }
}

signed main(){
    solve();
}



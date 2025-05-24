vector<ll> bit;
vector<ll> arr;
int n;
void update(int pos, ll delta){
    while (pos < n) {
        bit[pos] += delta;
        pos += pos & -pos;
    }
}

ll query(int pos){
    ll sum = 0;
    while (pos > 0) {
        sum += bit[pos];
        pos -= pos & -pos;
    }
    return sum;
}

int main(){
    cin>>tam;
    bit.assign(tam+1, 0);
    arr.resize(tam);
    
    fore(i, 0, n){
        cin >> arr[i];
        update(i+1, arr[i]);//1 indexed
    }
    
    // Ejemplo de consultas
    int q;
    while (q--) {
        int tipo;
        cin >> tipo;
        if (tipo == 1) { // Suma en el rango [1, pos]
            int pos;
            cin >> pos;
            cout << query(pos) << endl;
        } else if (tipo == 2) { // Actualizar arr[i] a un nuevo valor
            int pos;
            ll nuevo;
            cin >> pos >> nuevo;
            update(pos, nuevo - arr[pos-1]);
            arr[pos-1] = nuevo;
        }
    }
}

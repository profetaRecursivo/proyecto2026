//da la cantidad de abiertos o cerrados que faltan emparejar
struct Item{
    //algun atributo
    int open, close;
    Item(int _o = 0, int _c = 0){
        open = _o;
        close = _c;
    }

    static Item merge(const Item& a, const Item& b){
        int match=min(a.open, b.close);
        int o = a.open + b.open - match;
        int c = a.close + b.close - match;
        return Item(o, c);
    }
};

struct Nodo {
    Item value;
    Nodo *izq = nullptr, *der = nullptr;
};

void update(Nodo*& node, ll inicio, ll fin, ll pos, Item it) {
    if (!node) node = new Nodo();
    if (inicio == fin) {
        if(it.close == 999)
            if(node->value.close == 1){
                node->value.close = 0;
                node->value.open = 1;
            }else{
                node->value.close = 1;
                node->value.open = 0;
            }
        else
            node->value = it;
        return;
    }
    ll mid = (inicio + fin) / 2;
    if (pos <= mid)
        update(node->izq, inicio, mid, pos, it);
    else
        update(node->der, mid + 1, fin, pos, it);
    Item izqVal = node->izq ? node->izq->value : Item();
    Item derVal = node->der ? node->der->value : Item();
    node->value = Item::merge(izqVal, derVal);
}

Item query(Nodo* node, ll inicio, ll fin, ll l, ll r) {
    if (!node || r < inicio || l > fin) return Item();
    if (l <= inicio && fin <= r) return node->value;
    ll mid = (inicio + fin) / 2;
    return Item::merge(query(node->izq, inicio, mid, l, r),
           query(node->der, mid + 1, fin, l, r));
}

void solve(){
    Nodo* seg = new Nodo();
   string s;cin>>s;
   int idx = 1;
   for(char x:s){
    Item it;
    if(x == '0'){
        it = Item(1, 0);
    }else{
        it = Item(0, 1);
    }
    update(seg, 1, sz(s), idx++, it);
   }

   int q;cin>>q;
   while(q--){
    int t;cin>>t;
    if(t == 1){
        int pos;cin>>pos;
        update(seg, 1, sz(s), pos, Item(0, 999));
    }else{
        int l, r;cin>>l>>r;
        auto weee = query(seg, 1, sz(s), l, r);
        cout<<weee.close + weee.open<<'\n';
    }
   }
}
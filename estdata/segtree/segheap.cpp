struct Item{
    //algun atributo
    static Item merge(const Item& a, const Item& b){

    }
};

struct Nodo {
	Item value;
	Nodo *izq = nullptr, *der = nullptr;
};

void update(Nodo*& node, ll inicio, ll fin, ll pos, Item& val) {
	if (!node) node = new Nodo();
	if (inicio == fin) {//la actualizacion, puede ser suma o asignacion o lo que sea, piensa bien
		node->value = val;
		return;
	}
	ll mid = (inicio + fin) / 2;
	if (pos <= mid)
		update(node->izq, inicio, mid, pos, val);
	else
		update(node->der, mid + 1, fin, pos, val);
	//esto esta interesante, que es el elemento neutro?
	Item& izqVal = node->izq ? node->izq->value : /*neutro*/;
	Item& derVal = node->der ? node->der->value : /*neutro*/;
	node->value = Item::merge(izqVal, derVal);
}

Item query(Nodo* node, ll inicio, ll fin, ll l, ll r) {
	if (!node || r < inicio || l > fin) return 0;
	if (l <= inicio && fin <= r) return node->value;
	ll mid = (inicio + fin) / 2;
	return Item::merge(query(node->izq, inicio, mid, l, r),
		   query(node->der, mid + 1, fin, l, r));
}
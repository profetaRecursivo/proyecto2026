const int tam = POTENCIA DE DOS;//no probado
struct Node {
	//atributos
	Node(/*parametros*/) {
		
	}
	static inline Node merge(const Node& a, const Node& b) {
		
	}
};
int n;
Node t[2 * tam];

void build() {
	for (int i = n - 1; i > 0; --i) {
		t[i] = Node::merge(t[i << 1], t[(i << 1) | 1]);
	}
}

void update(int p, Node value) {
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = Node::merge(t[(p >> 1) << 1], t[((p >> 1) << 1) | 1]);
}

Node query(int l, int r) {
	r++;
	Node izq, der;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) izq = Node::merge(izq, t[l++]);
		if (r & 1) der = Node::merge(t[--r], der);
	}
	return Node::merge(izq, der);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int key, pri, sz = 1;
    Node *l = nullptr, *r = nullptr;
    Node(int k) : key(k), pri(rng()) {}
};

int sz(Node* t) { return t ? t->sz : 0; }
void upd(Node* t) { if (t) t->sz = 1 + sz(t->l) + sz(t->r); }

// pair<Node*, Node*> split(Node* t, int k) {
//     if (!t) return {nullptr, nullptr};
//     if (t->key < k) {
//         auto [a, b] = split(t->r, k);
//         t->r = a; upd(t);
//         return {t, b};
//     } else {
//         auto [a, b] = split(t->l, k);
//         t->l = b; upd(t);
//         return {a, t};
//     }
// }

pair<Node*, Node*> split(Node* t, int k) {//treap implicito
    if (!t) return {nullptr, nullptr};
    if (sz(t->l) < k) {
        auto [a, b] = split(t->r, k - sz(t->l) - 1);
        t->r = a; upd(t);
        return {t, b};
    } else {
        auto [a, b] = split(t->l, k);
        t->l = b; upd(t);
        return {a, t};
    }
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) { a->r = merge(a->r, b); upd(a); return a; }
    else                 { b->l = merge(a, b->l); upd(b); return b; }
}
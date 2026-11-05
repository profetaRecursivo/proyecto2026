#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int key, pri, sz = 1;
    Node *l = nullptr, *r = nullptr;
    Node(int k) : key(k), pri(rng()) {}
};

int sz(Node* t) { return t ? t->sz : 0; }
void upd(Node* t) { if (t) t->sz = 1 + sz(t->l) + sz(t->r); }

// Divide el árbol en dos: 
// 'a' tendrá elementos con key < k
// 'b' tendrá elementos con key >= k
pair<Node*, Node*> split(Node* t, int k) {
    if (!t) return {nullptr, nullptr};
    if (t->key < k) {
        auto [a, b] = split(t->r, k);
        t->r = a; 
        upd(t);
        return {t, b};
    } else {
        auto [a, b] = split(t->l, k);
        t->l = b; 
        upd(t);
        return {a, t};
    }
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) { 
        a->r = merge(a->r, b); 
        upd(a); 
        return a; 
    } else { 
        b->l = merge(a, b->l); 
        upd(b); 
        return b; 
    }
}

// Operaciones básicas para Treap por valores:

void insert(Node*& t, int val) {
    auto [a, b] = split(t, val);
    t = merge(merge(a, new Node(val)), b);
}

void erase(Node*& t, int val) {
    auto [a, b] = split(t, val);
    auto [b1, b2] = split(b, val + 1); // b1 contiene los nodos con key == val
    // Si se desea eliminar todas las instancias de 'val':
    t = merge(a, b2);
}

bool find(Node* t, int val) {
    if (!t) return false;
    if (t->key == val) return true;
    if (val < t->key) return find(t->l, val);
    return find(t->r, val);
}

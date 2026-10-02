#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ====================================================================
// 1. ESPECÍFICO DEL PROBLEMA (Solo cambias esto según el problema)
// ====================================================================

struct Tag {
    ll add = 0;

    bool empty() const {
        return add == 0;
    }

    // Cómo se compone un nuevo tag con el tag acumulado previo
    void combine(const Tag& t) {
        add += t.add;
    }
};

struct Info {
    ll sum = 0;

    // Cómo un tag modifica a esta información en un rango de longitud 'len'
    void apply(const Tag& t, ll len) {
        sum += t.add * len;
    }

    // Cómo se unen los valores de dos hijos
    static Info merge(const Info& a, const Info& b) {
        return Info{a.sum + b.sum};
    }
};

// ====================================================================
// 2. MOTOR GENÉRICO PERSISTENTE (Nunca se toca entre problemas)
// ====================================================================

struct Node {
    Info info;
    Tag tag;
    Node *izq, *der;

    Node(Info i = Info(), Tag t = Tag(), Node* l = nullptr, Node* r = nullptr)
        : info(i), tag(t), izq(l), der(r) {}
};

Node* nulo = new Node();

void push(Node* node, ll b, ll e) {
    if (node == nullptr || node == nulo || node->tag.empty()) return;

    if (b != e) {
        ll mid = b + (e - b) / 2;

        // Hijo izquierdo
        Node* izq = (node->izq == nullptr || node->izq == nulo)
                    ? new Node(Info(), Tag(), nulo, nulo)
                    : new Node(*node->izq);
        izq->tag.combine(node->tag);
        izq->info.apply(node->tag, mid - b + 1);
        node->izq = izq;

        // Hijo derecho
        Node* der = (node->der == nullptr || node->der == nulo)
                    ? new Node(Info(), Tag(), nulo, nulo)
                    : new Node(*node->der);
        der->tag.combine(node->tag);
        der->info.apply(node->tag, e - mid);
        node->der = der;
    }

    node->tag = Tag(); // Resetea el tag
}

Node* update(Node* node, ll b, ll e, ll i, ll j, const Tag& val) {
    if (node == nullptr || node == nulo) node = nulo;
    Node* ans = (node == nulo) ? new Node(Info(), Tag(), nulo, nulo) : new Node(*node);

    if (i <= b && e <= j) {
        ans->info.apply(val, e - b + 1);
        ans->tag.combine(val);
        return ans;
    }

    push(ans, b, e);
    ll mid = b + (e - b) / 2;

    if (j <= mid) {
        ans->izq = update(ans->izq, b, mid, i, j, val);
    } else if (i > mid) {
        ans->der = update(ans->der, mid + 1, e, i, j, val);
    } else {
        ans->izq = update(ans->izq, b, mid, i, j, val);
        ans->der = update(ans->der, mid + 1, e, i, j, val);
    }

    Info info_izq = (ans->izq && ans->izq != nulo) ? ans->izq->info : Info();
    Info info_der = (ans->der && ans->der != nulo) ? ans->der->info : Info();
    ans->info = Info::merge(info_izq, info_der);

    return ans;
}

Info query(Node* node, ll b, ll e, ll i, ll j, Tag tag_acum = Tag()) {
    if (node == nullptr || node == nulo) {
        ll l = max(b, i);
        ll r = min(e, j);
        if (l > r) return Info();
        Info res = Info();
        res.apply(tag_acum, r - l + 1);
        return res;
    }

    if (i <= b && e <= j) {
        Info res = node->info;
        res.apply(tag_acum, e - b + 1);
        return res;
    }

    ll mid = b + (e - b) / 2;
    Tag cur_tag = tag_acum;
    cur_tag.combine(node->tag);

    if (j <= mid) {
        return query(node->izq, b, mid, i, j, cur_tag);
    }
    if (i > mid) {
        return query(node->der, mid + 1, e, i, j, cur_tag);
    }

    return Info::merge(
        query(node->izq, b, mid, i, j, cur_tag),
        query(node->der, mid + 1, e, i, j, cur_tag)
    );
}

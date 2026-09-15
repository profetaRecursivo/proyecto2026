#include <iostream>
#include <algorithm>

using namespace std;

const int tam = 100010;
const int INF = 1e9;

struct Node {
    int val;
    Node(int v = -INF) : val(v) {}
};

Node merge(Node a, Node b) {
    return Node(max(a.val, b.val));
}

int arr[tam];
Node tr[4 * tam];
int lazy[4 * tam];

void push(int b, int e, int node) {
    if (lazy[node] != 0) {
        tr[node].val += lazy[node];//aplicacion de la operacion en rango

        if (b != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
//si falla usar:
void push(int node, int b, int e){
    if(lazy[node] != 0){
        if(lazy[node] == ORIGINAL){
            tr[node] = suma_or[node];
        } else {
            tr[node] = 0;
        }
        if(b != e){
            int l = 2 * node, r = l + 1;
            lazy[l] = lazy[node];
            if(lazy[l] == ORIGINAL) tr[l] = suma_or[l];
            else tr[l] = 0;
            lazy[r] = lazy[node];
            if(lazy[r] == ORIGINAL) tr[r] = suma_or[r];
            else tr[r] = 0;
        }
        
        lazy[node] = 0;
    }
}

void build(int b, int e, int node) {
    lazy[node] = 0;
    if (b == e) {
        tr[node] = Node(arr[b]);
        return;
    }
    int l = node * 2, r = l + 1, mid = (b + e) / 2;
    build(b, mid, l);
    build(mid + 1, e, r);
    tr[node] = merge(tr[l], tr[r]);
}

void update_range(int b, int e, int node, int i, int j, int val) {
    push(b, e, node);
    if (e < i || b > j) return;
    if (i <= b && e <= j) {
        lazy[node] += val;
        push(b, e, node);
        return;
    }

    int mid = (b + e) / 2, l = node * 2, r = l + 1;
    update_range(b, mid, l, i, j, val);
    update_range(mid + 1, e, r, i, j, val);
    tr[node] = merge(tr[l], tr[r]);
}

Node query(int b, int e, int node, int i, int j) {
    push(b, e, node);
    if (e < i || b > j) return Node(-INF);
    if (i <= b && e <= j) return tr[node];
    int mid = (b + e) / 2, l = node * 2, r = l + 1;
    return merge(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
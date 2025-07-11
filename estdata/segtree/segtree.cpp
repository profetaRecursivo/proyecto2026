#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;

struct Node{
    int x;
    //algo
    Node(int _x){x = _x;}
    static Node merge(const Node&a, const Node& b){
        return Node(a.x + b.x);
    }
};

Node t[4*tam];
int arr[tam];

void init(int b, int e, int node){
    if(b == e){
        t[node] = Node(arr[b]);
        return;
    }
    int mid = (b+e)>>1, l = node << 1 + 1, r = l+1;
    init(b, mid, l);
    init(mid+1, e, r);
    t[node] = Node::merge(t[l], t[r]);
}

Node query(int b, int e, int node, int i, int j){
    if(i<=b and j>=e){
        return t[node];
    }
    int mid = (b+e)>>1, l = node << 1 + 1, r = l+1;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid+1, e, r, i, j);
    return Node::merge(query(b, mid, l, i, j), query(mid+1, e, r, i, j));
}

void update(int b, int e, int node, int pos, Node& val){
    if(b == e){
        //reemplazar, sumar, xor, lo que sea
        t[node] = val;
        return;
    }
    int mid = (b+e)>>1, l = node << 1 + 1, r = l+1;
    if(pos <= mid){
        update(b, mid, l, pos, val);
    }else{
        update(mid+1, e, r, pos, val);
    }
    t[node] = Node::merge(t[l], t[r]);
}
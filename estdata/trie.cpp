#include <bits/stdc++.h>
using namespace std;

const int ALPH = 26; 

struct Node {
    int arr[ALPH];   // hijos por índice; -1 si no existe
    int pasadas;        // cuántas cadenas pasan por aquí (incluye finales)
    int endCnt;      // cuántas cadenas terminan exactamente en este nodo
    Node() {
        for (int i = 0; i < ALPH; ++i) arr[i] = -1;
        pasadas = 0;
        endCnt = 0;
    }
};

vector<Node> trie;

int newNode() {
    trie.emplace_back();
    return (int)trie.size() - 1;
}

void initTrie(int reserveNodes = 1 << 10) {
    trie.clear();
    trie.reserve(reserveNodes);
    newNode(); // raíz = 0
}

// Inserta una cadena (puede repetirse varias veces)
void insertTrie(const string &s) {
    int v = 0;
    trie[v].pasadas++;
    for (char ch : s) {
        int idx = ch - 'a';
        if (trie[v].arr[idx] == -1) trie[v].arr[idx] = newNode();
        v = trie[v].arr[idx];
        trie[v].pasadas++;
    }
    trie[v].endCnt++;
}

// Devuelve true si existe al menos una ocurrencia exacta de s
bool exists(const string &s) {
    int v = 0;
    for (char ch : s) {
        int idx = ch - 'a';
        if (trie[v].arr[idx] == -1) return false;
        v = trie[v].arr[idx];
    }
    return trie[v].endCnt > 0;
}

// Borra UNA ocurrencia de s. Retorna true si se borró, false si no existía.
bool eraseTrie(const string &s) {
    if (!exists(s)) return false;
    int v = 0;
    trie[v].pasadas--;
    for (char ch : s) {
        int idx = ch - 'a';
        int to = trie[v].arr[idx];
        v = to;
        trie[v].pasadas--;
    }
    trie[v].endCnt--;
    return true;
}

// Cuenta cuántas cadenas insertadas tienen prefijo pref
int countPrefix(const string &pref) {
    int v = 0;
    for (char ch : pref) {
        int idx = ch - 'a';
        if (idx < 0 || idx >= ALPH) return 0;
        if (trie[v].arr[idx] == -1) return 0;
        v = trie[v].arr[idx];
    }
    return trie[v].pasadas;
}
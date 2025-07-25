//Given an array of n integers, your task is to find all integers that are the xor sum in some subarray.

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
void fwht(vector<ull> &a, bool inv) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; ++j) {
                ull u = a[i + j];
                ull v = a[i + j + len];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }
    if (inv) {
        for (ull &x : a) x /= n;
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    // prefijos del xor para los rangos
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] ^ a[i];
    // cosas de la fwht
    int maxVal = *max_element(p.begin(), p.end());
    int B = 0;
    while ((1 << B) <= maxVal) ++B;
    int M = 1 << B;
    // frecuencias
    vector<ull> A(M, 0);
    map<int, int> freq;
    bool hasZero = false;
    for (int x : p) {
        A[x]++;
        if (++freq[x] >= 2) hasZero = 1;
    }
    fwht(A, false);
    for (int i = 0; i < M; ++i)
        A[i] = A[i] * A[i];
    fwht(A, true);
    // los xor posibles
    vector<int> res;
    res.reserve(M);
    for (int i = 0; i < M; ++i) {
        if (A[i] > 0) {
            if (i == 0 && !hasZero) continue; 
            //i ya es tu respuesta
            res.push_back(i);
        }
    }
    cout<<(int)res.size()<<'\n';
    for(int x:res)cout<<x<<' ';
}

ll mergeSort(vector<int>& a, int l, int r, vector<int>& aux) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    ll inv = 0;
    inv += mergeSort(a, l, m, aux);
    inv += mergeSort(a, m, r, aux);

    int i = l, j = m, k = 0;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
            inv += m - i; // todos los elementos restantes en la izquierda son > a[j-1]
        }
    }
    while (i < m) aux[k++] = a[i++];
    while (j < r) aux[k++] = a[j++];
    for (int t = 0; t < k; t++) a[l + t] = aux[t];
    return inv;
}
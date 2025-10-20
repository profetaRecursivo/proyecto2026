// Suma `val` al rango [l, r]
void range_add(int l, int r, ll val) {
    update(l, val);      
    update(r + 1, -val); 
}

ll point_query(int i) {
    return query(i);
}

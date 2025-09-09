//true si es que 1 y 2 intersectan en alguen punto
bool intersect(int l1, int r1, int l2, int r2){
    return max(l1, l2) <= min(r1, r2);
}
//true si es que 1 y 2 intersectan en alguen punto
bool fun(int l1, int r1, int l2, int r2){
    return (r2 >= l1 && (l2 <= l1)) or((l2 <= r1) && (r2 <= r1));
}
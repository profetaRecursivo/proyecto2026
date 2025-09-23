//s el es set con los segmentos
//para funcionar correcto, no debe haber segmentos solapados

bool contiene(int x) {
    auto it = s.upper_bound({x, INF});
    if(it == s.begin()) return false;
    --it;
    return it->first <= x and x <= it->second;
}
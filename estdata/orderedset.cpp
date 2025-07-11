#include <bits/stdc++.h> 
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    std::less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<typename T>//esto se puede borrar si pongo de argumento que llega un oset de int, double, etc
// Cuántos elementos estrictamente menores que x (< x)
int count_less(const ordered_set<T>& os, T x) {
    return os.order_of_key(x);
}
template<typename T>
// Cuántos elementos menores o iguales que x (≤ x)
int count_less_equal(const ordered_set<T>& os, T x) {
    return os.order_of_key(x + 1);  // SOLO si T es numérico (int, long long)
}
template<typename T>
// Cuántos elementos estrictamente mayores que x (> x)
int count_greater(const ordered_set<T>& os, T x) {
    return (int)os.size() - os.order_of_key(x + 1);  // SOLO si T es numérico
}
template<typename T>
// Cuántos elementos mayores o iguales que x (≥ x)
int count_greater_equal(const ordered_set<T>& os, T x) {
    return (int)os.size() - os.order_of_key(x);
}
//greater or less

signed main(){
    ordered_set<int> oset;
    oset.insert(3);
    oset.insert(5);
    oset.insert(1);
    //[1 3 5]
    //[0 1 2]
    //cantidad de elementos menores a 4, o 
    //como decir, en que posicion deberia de estar el 4
    cout<<(int)oset.order_of_key(2)<<endl;
    cout<<*(oset.find_by_order(0))<<endl;
}

//cantidad de elementos en un rango:
//o_set.order_of_key(r+1) – o_set.order_of_key(l)
//para datos numericos
template<typename T>
int count_less(const ordered_set<T>& os, const T& x) {
    return os.order_of_key(x);  // < x
}

template<typename T>
int count_less_equal(const ordered_set<T>& os, const T& x) {
    // upper_bound(x) da el primer > x → entonces los <= x están antes
    return os.order_of_key(os.upper_bound(x));
}

template<typename T>
int count_greater(const ordered_set<T>& os, const T& x) {
    // > x = total - ≤ x
    return os.size() - count_less_equal(os, x);
}

template<typename T>
int count_greater_equal(const ordered_set<T>& os, const T& x) {
    // ≥ x = total - < x
    return os.size() - count_less(os, x);
}

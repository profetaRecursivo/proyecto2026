ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return {1, 0};
    int x1, y1;
    auto aux = extgcd(b, a % b);
    x1 = aux.first;
    y1 = aux.second;
    ll x = y1;
    ll y = x1 - (a / b) * y1;
    return {x, y};
}
pair<bool, pair<ll, ll>> solve2cong(ll a1, ll m1, ll a2, ll m2) {
    ll g = gcd(m1, m2);
    if ((a1 - a2) % g != 0) {
        return {false, {0, 0}};
    }
    m1 /= g;
    m2 /= g;
    auto aux = extgcd(m1, m2);
    int x = aux.first, y = aux.second;
    ll k = (a2 - a1) / g;
    ll sol = a1 + (x * k % m2) * (m1 * g);
    ll curr_lcm = lcm(m1 * g, m2 * g);
    sol = (sol % curr_lcm + curr_lcm) % curr_lcm;
    return {true, {sol, curr_lcm}};
}

// pair<bool, pair<ll, ll>> generalCRT(const vector<ll>& residuos, 
//                                                 const vector<ll>& mods) {
//     if (residuos.empty()) return {true, {0, 1}};
    
//     ll curr_x = residuos[0];
//     ll curr_lcm = mods[0];
    
//     for (int i = 1; i < sz(residuos); i++) {
//         auto aux = solve2cong(curr_x, curr_lcm, 
//                                                           residuos[i], mods[i]);
//         auto hassol = aux.first;
//         auto sol =aux.second; 
//         if (!hassol) {
//             return {false, {0, 0}};
//         }
//         curr_x = sol.first;
//         curr_lcm = sol.second;
//     }
    
//     return {true, {curr_x, curr_lcm}};
// }
///// x = a_i mod m_i
pair<bool, pair<ll, ll>> robustCRT(const vector<ll>& a, const vector<ll>& m) {
    ll x = 0, lcm_val = 1;   
    for (int i = 0; i < sz(a); i++) {
        ll g = gcd(lcm_val, m[i]);
        if ((a[i] - x) % g != 0) {
            return {false, {0, 0}};
        }
        auto aux = extgcd(lcm_val / g, m[i] / g);
        auto p = aux.first;
        auto q = aux.second;
        ll k = (a[i] - x) / g;
        x = x + (k * p % (m[i] / g)) * lcm_val;
        lcm_val = lcm(lcm_val, m[i]);
        x = (x % lcm_val + lcm_val) % lcm_val;
    }
    return {true, {x, lcm_val}};
}
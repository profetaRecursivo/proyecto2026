//O(n + maxelement)
Dado un conjunto de números, quieres sumarlos todos en pares de manera que el costo total de sumar sea mínimo.
void solve() {
    int n;
    cin >> n;
    int cnt[MAX_VAL];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    queue<int> q1, q2;
    for(int i = 1; i < MAX_VAL; ++i) {
        while(cnt[i]--) {
            q1.push(i);
        }
    }
    int result = 0;
    auto getMin = [&]() {
        if (q1.empty()) {
            int val = q2.front(); q2.pop();
            return val;
        }
        if (q2.empty()) {
            int val = q1.front(); q1.pop();
            return val;
        }
        if (q1.front() < q2.front()) {
            int val = q1.front(); q1.pop();
            return val;
        } else {
            int val = q2.front(); q2.pop();
            return val;
        }
    };
    while(sz(q1) + sz(q2) >= 2) {
        int a = getMin();
        int b = getMin();
        int suma = a + b;
        result += suma;
        q2.push(suma);
    }
    cout << result << '\n';
}
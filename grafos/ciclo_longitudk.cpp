#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<int> color;
vector<vector<int>> parent;
vector<vector<bool>> dp;

bool hayCicloLongitudK(vector<int>& ciclo) {
    color.resize(n);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, k - 1);
    for (int i = 0; i < n; i++) color[i] = dist(rng);

    int totalMasks = 1 << k;
    dp.assign(totalMasks, vector<bool>(n, false));
    parent.assign(totalMasks, vector<int>(n, -1));

    for (int v = 0; v < n; v++)
        dp[1 << color[v]][v] = true;

    for (int mask = 0; mask < totalMasks; mask++) {
        for (int v = 0; v < n; v++) {
            if (!dp[mask][v]) continue;
            for (int u : adj[v]) {
                int c = color[u];
                if (mask & (1 << c)) continue;
                int newMask = mask | (1 << c);
                if (!dp[newMask][u]) {
                    dp[newMask][u] = true;
                    parent[newMask][u] = v;
                }
            }
        }
    }

    for (int mask = 0; mask < totalMasks; mask++) {
        if (__builtin_popcount(mask) != k) continue;
        for (int v = 0; v < n; v++) {
            if (!dp[mask][v]) continue;
            for (int u : adj[v]) {
                if (dp[1 << color[u]][u]) {
                    vector<int> path;
                    int cur = v, curMask = mask;
                    while (cur != -1) {
                        path.push_back(cur);
                        int prev = parent[curMask][cur];
                        if (prev == -1) break;
                        curMask ^= (1 << color[cur]);
                        cur = prev;
                    }
                    reverse(path.begin(), path.end());
                    path.push_back(u);
                    ciclo = path;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> k;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
    }

    vector<int> ciclo;
    int REPETICIONES = 30;
    bool existe = false;
    while (REPETICIONES--) {
        if (hayCicloLongitudK(ciclo)) {
            existe = true;
            break;
        }
    }

    if (!existe) {
        cout << "NO\n";
    } else {
        cout << "SI\n";
        for (int v : ciclo) cout << v + 1 << " ";
        cout << "\n";
    }
}
//O(2^k*(n+m))aprox
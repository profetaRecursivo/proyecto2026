struct edge {int u, v, w;};
//ciclo negativo alcanzable desde source
bool bellmanFord(int n, vector<edge>& edges, int source) {
    vector<int> dist(n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != INF and dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    // revisar si existe ciclo negativo
    for (auto& e : edges) {
        if (dist[e.u] != INF and dist[e.u] + e.w < dist[e.v]) {
            return 1; 
        }
    }
    return 0;
}
struct Dinitz{
    Dinitz(int n, int s, int t) {init(n, s, t);}
    void init(int n, int s, int t)
    {
        S = s, T = t;
        nodes = n;
        G.clear(), G.resize(n);
        Q.resize(n);
    }
    struct flowEdge
    {
        int to, rev, f, cap;
    };

    vector<vector<flowEdge> > G;
    void addEdge(int st, int en, int cap) {
        flowEdge A = {en, sz(G[en]), 0, cap};
        flowEdge B = {st, sz(G[st]), 0, 0};
        G[st].push_back(A);
        G[en].push_back(B);
    }

    int nodes, S, T;
    vector<int> work, lvl;
    vector<int> Q;

    bool bfs() {
        int qt = 0;
        Q[qt++] = S;
        lvl.assign(nodes, -1);
        lvl[S] = 0;
        for (int qh = 0; qh < qt; qh++) {
            int v = Q[qh];
            for (auto[u, rev, f, cap] : G[v]) {
                if (cap <= f or lvl[u] != -1) continue;
                lvl[u] = lvl[v] + 1;
                Q[qt++] = u;
            }
        }
        return lvl[T] != -1;
    }

    int dfs(int v, int ff) {
        if (v == T or ff == 0) return ff;
        for (int &i = work[v]; i < sz(G[v]); i++) {
            auto&[u, rev, f, cap] = G[v][i];
            if (cap <= f or lvl[u] != lvl[v] + 1) continue;
            int df = dfs(u, min(ff, cap - f));
            if (df) {
                f += df;
                G[u][rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    int maxFlow() {
        int flow = 0;
        while (bfs()) {
            work.assign(nodes, 0);
            while (1) {
                int df = dfs(S, INF);
                if (df == 0) break;
                flow += df;
            }
        }
        return flow;
    }
};

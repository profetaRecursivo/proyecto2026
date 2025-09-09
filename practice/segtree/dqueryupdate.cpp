#include <bits/stdc++.h>
using namespace std;
//MO N^(5/3)
struct Query { int l, r, t, idx; };
struct Update { int pos, prev, now; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> arr(n+1);
    vector<int> allVals;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        allVals.push_back(arr[i]);
    }

    vector<tuple<int,int,int>> inputOps;
    for (int i = 0; i < q; ++i) {
        int type; cin >> type;
        if (type == 1) {
            int pos, x; cin >> pos >> x;
            inputOps.emplace_back(1,pos,x);
            allVals.push_back(x);
        } else {
            int l, r; cin >> l >> r;
            inputOps.emplace_back(2,l,r);
        }
    }
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());
    auto compress = [&](int x){
        return int(lower_bound(allVals.begin(), allVals.end(), x) - allVals.begin());
    };

    for (int i = 1; i <= n; ++i) arr[i] = compress(arr[i]);

    // guardo snapshot del arreglo inicial (antes de aplicar updates)
    vector<int> origArr(n+1);
    for (int i = 1; i <= n; ++i) origArr[i] = arr[i];

    vector<Query> queries;
    vector<Update> updates;
    int qIdx = 0;

    // proceso operaciones (registro updates con prev/now)
    for (auto &op : inputOps) {
        int type = get<0>(op), a = get<1>(op), b = get<2>(op);
        if (type == 1) {
            int pos = a, x = compress(b);
            updates.push_back({pos, arr[pos], x});
            arr[pos] = x; // muta arr para que siguientes updates usen el valor correcto
        } else {
            int l = a, r = b;
            queries.push_back({l, r, (int)updates.size(), qIdx++});
        }
    }

    // currArr debe empezar en el estado inicial (origArr), no en arr final
    vector<int> currArr(n+1);
    for (int i = 1; i <= n; ++i) currArr[i] = origArr[i];

    // freq según tamaño de compresión
    vector<int> freq((int)allVals.size() + 5, 0);
    int distinct = 0;
    auto add = [&](int pos){
        int v = currArr[pos];
        if (freq[v] == 0) ++distinct;
        ++freq[v];
    };
    auto removeVal = [&](int pos){
        int v = currArr[pos];
        --freq[v];
        if (freq[v] == 0) --distinct;
    };
    auto apply = [&](const Update &u, int L, int R){
        int pos = u.pos;
        if (L <= pos && pos <= R) {
            removeVal(pos);
            currArr[pos] = u.now;
            add(pos);
        } else currArr[pos] = u.now;
    };
    auto rollback = [&](const Update &u, int L, int R){
        int pos = u.pos;
        if (L <= pos && pos <= R) {
            removeVal(pos);
            currArr[pos] = u.prev;
            add(pos);
        } else currArr[pos] = u.prev;
    };

    // ordenar queries: bloque ~ n^(2/3) (evitamos 0)
    int BLOCK = max(1, (int)pow(n, 2.0/3.0));
    sort(queries.begin(), queries.end(), [&](const Query &A, const Query &B){
        int blockA = A.l / BLOCK, blockB = B.l / BLOCK;
        if (blockA != blockB) return blockA < blockB;
        int blockRA = A.r / BLOCK, blockRB = B.r / BLOCK;
        if (blockRA != blockRB) return blockRA < blockRB;
        return A.t < B.t;
    });

    vector<int> ans(qIdx);
    int L = 1, R = 0, T = 0;
    for (auto &qu : queries) {
        while (L > qu.l) add(--L);
        while (R < qu.r) add(++R);
        while (L < qu.l) removeVal(L++);
        while (R > qu.r) removeVal(R--);

        while (T < qu.t) apply(updates[T++], L, R);
        while (T > qu.t) rollback(updates[--T], L, R);

        ans[qu.idx] = distinct;
    }

    for (int i = 0; i < qIdx; ++i) cout << ans[i] << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fore(i, a, b) for(int i = (a); i<(b); i++)
#define FOR(i, n) for(int i = 0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using vi = vector<int>;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;

const int MAXN = 100001;
const int K = 17;

int st[K + 1][MAXN];

int f(int a, int b){
    return min(a, b);
}
void initsparse(vector<int>& array, int N){
    copy(array.begin(), array.end(), st[0]);
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int query(int L, int R) {
    int k = 31 - __builtin_clz(R - L + 1);
    return f(st[k][L], st[k][R - (1 << k) + 1]);
}
int tc = 1;
void solve(){
    printf("Scenario #%d:\n", tc++);
    int n, q;cin>>n>>q;
    vector<int> arr(n);
    fore(i, 0, n)cin>>arr[i];
    initsparse(arr, n);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = query(l-1, r-1);
        printf("%d\n", ans);
    }
}

signed main(){
    int t = 1;
    scanf("%d", &t);
    while(t--){
        solve();
    }
}
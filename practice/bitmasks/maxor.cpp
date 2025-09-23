//maxmimizar sum[l,r](i or j)
int64 onesUpTo(int64 x, int k){
    if(x < 0) return 0;
    int64 period = 1LL << (k+1);
    int64 half = 1LL << k;
    int64 full = (x + 1) / period;
    int64 rem = (x + 1) % period;
    return full * half + max(0LL, rem - half);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int64 l, r;
        cin >> l >> r;
        int64 n = r - l + 1;
        int64 ans = 0;
        int maxb = 0;
        while((1LL << maxb) <= r) ++maxb;
        for(int k = 0; k <= maxb; ++k){
            int64 cnt = onesUpTo(r, k) - onesUpTo(l - 1, k);
            int64 ones_in_or = min(n, 2 * cnt);
            ans += ones_in_or * (1LL << k);
        }
        cout << ans << "\n";
    }
    return 0;
}
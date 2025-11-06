// Find the number of integer pairs x, y such that sum (1 to n){|x - x_i| + |y - y_i|} <= D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int D;
    if (!(cin >> N >> D)) return 0;
    vector<int> xs(N), ys(N);
    for (int i = 0; i < N; ++i) cin >> xs[i] >> ys[i];

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    // pref sums as long long
    vector<ll> prefX(N+1,0), prefY(N+1,0);
    for (int i = 0; i < N; ++i) { prefX[i+1] = prefX[i] + xs[i]; prefY[i+1] = prefY[i] + ys[i]; }

    auto S_at = [&](const vector<int>& A, const vector<ll>& pref, ll x) -> ll {
        // S(x) = sum |x - A[i]|
        int pos = upper_bound(A.begin(), A.end(), (int)x) - A.begin(); // number <= x
        ll sumLeft = pref[pos];
        ll sumRight = pref[A.size()] - sumLeft;
        ll cntLeft = pos;
        ll cntRight = (int)A.size() - pos;
        return x*cntLeft - sumLeft + sumRight - x*cntRight;
    };

    // function to find leftmost integer in [low,high] with S_at(...) <= D; returns high+1 if none
    auto find_leftmost = [&](const vector<int>& A, const vector<ll>& pref, ll low, ll high, int D) -> ll {
        ll lo = low, hi = high;
        ll ans = high + 1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (S_at(A, pref, mid) <= D) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    };
    auto find_rightmost = [&](const vector<int>& A, const vector<ll>& pref, ll low, ll high, int D) -> ll {
        ll lo = low, hi = high;
        ll ans = low - 1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (S_at(A, pref, mid) <= D) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    };

    int xmin = xs.front(), xmax = xs.back();
    int ymin = ys.front(), ymax = ys.back();
    // safe search interval
    ll searchXL = (ll)xmin - D, searchXR = (ll)xmax + D;
    ll searchYL = (ll)ymin - D, searchYR = (ll)ymax + D;

    ll Lx = find_leftmost(xs, prefX, searchXL, searchXR, D);
    ll Rx = find_rightmost(xs, prefX, searchXL, searchXR, D);
    if (Lx > Rx) { // no x possible => answer 0
        cout << 0 << '\n';
        return 0;
    }

    ll Ly = find_leftmost(ys, prefY, searchYL, searchYR, D);
    ll Ry = find_rightmost(ys, prefY, searchYL, searchYR, D);
    if (Ly > Ry) {
        cout << 0 << '\n';
        return 0;
    }

    // We'll compute frequency: for s in [0..D], freq[s] = # integer y with S_y(y) == s.
    vector<int> freq(D+1, 0);

    // Compute Sy(Ly) via formula, then sweep y from Ly..Ry updating in O(1)
    ll Sy = S_at(ys, prefY, Ly);
    // pos_y = # { yi <= current y }
    int pos_y = upper_bound(ys.begin(), ys.end(), (int)Ly) - ys.begin();

    for (ll y = Ly; y <= Ry; ++y) {
        if (0 <= Sy && Sy <= D) freq[(int)Sy]++;

        // prepare next: delta = 2*pos_y - N (S(y+1) = S(y) + delta), delta uses pos = # <= y
        ll delta = 2LL * pos_y - N;
        Sy += delta;
        // advance pos_y by number of yi equal to y+1
        while (pos_y < N && ys[pos_y] == (int)(y+1)) ++pos_y;
    }

    // build cumulative: cum[t] = # y with S_y(y) <= t
    vector<ll> cum(D+1, 0);
    cum[0] = freq[0];
    for (int t = 1; t <= D; ++t) cum[t] = cum[t-1] + freq[t];

    // sweep x from Lx..Rx, compute Sx(Lx) then update
    ll Sx = S_at(xs, prefX, Lx);
    int pos_x = upper_bound(xs.begin(), xs.end(), (int)Lx) - xs.begin();
    ll ans = 0;
    for (ll x = Lx; x <= Rx; ++x) {
        ll rem = (ll)D - Sx;
        if (rem >= 0) {
            if (rem > D) rem = D; // safety but rem <= D by construction
            ans += cum[(int)rem];
        }
        // update Sx to x+1
        ll delta = 2LL * pos_x - N; // uses pos_x = # <= x
        Sx += delta;
        // advance pos_x by number of xi == x+1
        while (pos_x < N && xs[pos_x] == (int)(x+1)) ++pos_x;
    }

    cout << ans << '\n';
    return 0;
}
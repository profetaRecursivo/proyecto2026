
int subsum(vector<ll>& arr, ll x) {
    map<ll, int> freq;
    ll pref = 0, count = 0;
    freq[0] = 1;
    for (int num : arr) {
        pref += num;
        if (freq.find(pref - x) != freq.end()) {
            count += freq[pref - x];
        }
        freq[pref]++;
    }
    return count;
}
int lis(const vector<int>& arr) {
    vector<int> lis;
    vector<int> pred(sz(arr), -1);

    for (int i = 0; i < sz(arr); i++) {
        auto it = lower_bound(all(lis), arr[i]);
        if (it == lis.end()) {
            if (!lis.empty()) pred[i] = lis.back();
            lis.push_back(arr[i]);
        } else {
            *it = arr[i];
            if (it != lis.begin()) pred[i] = *(it - 1);
        }
    }
    vector<int> res;
    for (int i = lis.back(); i >= 0; i = pred[i]) {
        res.push_back(arr[i]);
        if (pred[i] == -1) break;
    }

    reverse(all(res));
    //en res se encuentra el lis
    return sz(lis);
}
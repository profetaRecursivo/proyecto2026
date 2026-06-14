int lis(const vector<int>& arr) {
	vector<int> lis;
	vector<int> pred(sz(arr), -1);
	for (int i = 0; i < sz(arr); i++) {
		auto it = lower_bound(lis.begin(), lis.end(), arr[i],
							  [&](int idx, int val) { return arr[idx] < val; });
		int pos = it - lis.begin();
		if (pos > 0) pred[i] = lis[pos - 1];
		if (it == lis.end())
			lis.push_back(i);
		else
			*it = i;
	}
	vector<int> res;
	for (int i = lis.back(); i != -1; i = pred[i]) res.push_back(arr[i]);
	reverse(res.begin(), res.end());
	return sz(lis);
}

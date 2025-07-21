
bool menor(string& a, bool inva, string& b, bool invb) {
	int n1 = sz(a);
	int n2 = sz(b);
	int i1 = inva ? n1 - 1 : 0;
	int i2 = invb ? n2 - 1 : 0;
	int step1 = inva ? -1 : 1;
	int step2 = invb ? -1 : 1;
	while (i1 >= 0 and i1 < n1 and i2 >= 0 and i2 < n2) {
		if (a[i1] < b[i2]) return 1;
		if (a[i1] > b[i2]) return 0;
		i1 += step1;
		i2 += step2;
	}
	return n1 < n2;
}
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	while (cin >> n >> k) {
		int m = n - k;
		double ans =
			(lgammal(n + 1) - lgammal(k + 1) - lgammal(m + 1)) / logl(10);
		int digits = (int)ans + 1;
		cout << digits << endl;
	}
	return 0;
}
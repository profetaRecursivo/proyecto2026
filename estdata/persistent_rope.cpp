const int tam = 10010;
char buff[tam];
#include <ext/rope>
using namespace __gnu_cxx;
void solve() {
	scanf("%s", buff);
	int q, t;
	scanf("%d", &q);
	vector<rope<char>> arr(1);
	arr[0] = rope<char>(buff);
	int x, y;
	while (q--) {
		scanf("%d", &t);
		arr.push_back(arr.back());
		if (t == 1) {
			scanf("%d %d", &x, &y);
			auto temp = arr.back().substr(x, y - x + 1);
			arr.back().erase(x, y - x + 1);
			arr[sz(arr) - 1] = temp.append(arr.back());
		} else if (t == 2) {
			scanf("%d %d", &x, &y);
			auto temp = arr.back().substr(x, y - x + 1);
			arr.back().erase(x, y - x + 1);
			arr[sz(arr) - 1] = arr.back().append(temp);
		} else if (t == 3) {
			scanf("%d", &y);
			printf("%c\n", arr.back()[y]);
		} else {
			scanf("%d %d", &x, &y);
			printf("%c\n", arr[x][y]);
		}
	}
}
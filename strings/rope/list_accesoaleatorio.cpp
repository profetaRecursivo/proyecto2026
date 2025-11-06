#include <ext/rope>
using namespace __gnu_cxx;
void solve() {
	rope<int> vec;
	int n, x, q;
	scanf("%d %d", &n, &q);
	fore(i, 0, n) {
		scanf("%d", &x);
		vec.push_back(x);
	}
	while (q--) {
        int t, k;
        scanf("%d %d", &t, &k);
        if(t == 1){
            scanf("%d", &x);
            vec.insert(k-1, x);
        }else if(t == 2){
            vec.erase(k-1, 1);
        }else{
            cout<<vec[k-1]<<'\n';
        }
    }
}
signed main() {
	int t = 1;
	//cin >> t;
	while (t--) { solve(); }
}
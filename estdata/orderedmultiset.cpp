// primero bits/stdc, std y luego las demas libs#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag,
			 tree_order_statistics_node_update>
	ordered_ms;

struct ordMultiset {
	int count;
	ordered_ms oset;

	ordMultiset() { count = 0; }
	// o que posicion le corresponde
	int count_oc(int x) {
		return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
	}
	void erase_one(int x) {
		auto it = oset.lower_bound({x, 0});
		if (it != oset.end() && it->first == x) { oset.erase(it); }
	}

	int count_less(int x) { return oset.order_of_key({x, 0}); }

	int count_less_equal(int x) { return oset.order_of_key({x + 1, 0}); }

	int count_greater(int x) {
		return (int)oset.size() - oset.order_of_key({x + 1, 0});
	}

	int count_greater_equal(int x) {
		return (int)oset.size() - oset.order_of_key({x, 0});
	}

	// 0 indexed
	int kth_element(int k) { return oset.find_by_order(k)->first; }

	void insert(int x) { oset.insert({x, count++}); }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<ll, int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag,
			 tree_order_statistics_node_update>
	ordered_ms;

struct ordMultiset {
	int count;
	ordered_ms oset;

	ordMultiset() { count = 0; }
	int count_oc(ll x) {
		return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
	}
	void erase_one(ll x) {
		auto it = oset.lower_bound({x, 0});
		if (it != oset.end() and it->first == x) { oset.erase(it); }
	}

	int count_less(ll x) { return oset.order_of_key({x, 0}); }

	int count_less_equal(ll x) { return oset.order_of_key({x + 1, 0}); }

	int count_greater(ll x) {
		return (int)oset.size() - oset.order_of_key({x + 1, 0});
	}

	int count_greater_equal(ll x) {
		return (int)oset.size() - oset.order_of_key({x, 0});
	}

	int kth_element(ll k) { return oset.find_by_order(k)->first; }

	void insert(ll x) { oset.insert({x, count++}); }
    void mergeFrom(const ordMultiset &other) {
        for (const auto &p : other.oset) {
            insert(p.first);
        }
    }
};

ordMultiset t[4*tam];
void build(int node, int b, int e) {
    if (b == e) {
        t[node].insert(arr[b]);
        return;
    }
    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left | 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    t[node].mergeFrom(t[left]);
    t[node].mergeFrom(t[right]);
}

int query(int node, int b, int e, int l, int r, ll x) {
    if (r < b or e < l) return 0;
    if (l <= b and e <= r) {
        return t[node].count_less(x);
    }
    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left | 1;
    return query(left, b, mid, l, r, x)
         + query(right, mid + 1, e, l, r, x);
}

void update(int node, int b, int e, int pos, ll oldv, ll newv) {
    t[node].erase_one(oldv);
    t[node].insert(newv);

    if (b == e) return;

    int mid = (b + e) >> 1;
    int left = node << 1;
    int right = left | 1;

    if (pos <= mid)
        update(left, b, mid, pos, oldv, newv);
    else
        update(right, mid + 1, e, pos, oldv, newv);
}
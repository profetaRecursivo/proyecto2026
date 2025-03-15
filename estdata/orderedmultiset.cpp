#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef pair<int, int> pii;


typedef tree<pii, null_type, less<pair<int, int>>, rb_tree_tag,
			 tree_order_statistics_node_update>
	ordered_ms;

ordered_ms oset;
// oset como atributo o algo

int count(int x) {
	// Elementos < {x+1, 0} menos elementos < {x, 0}
	return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
}

void erase_one(int x) {
	auto it = oset.lower_bound({x, 0});
	if (it != oset.end() && it->first == x) { oset.erase(it); }
}

int kth_element(int k) { return oset.find_by_order(k)->first; }


struct ordMultiset
{
    int count;
	ordered_ms oset;
	ordMultiset(){
		count = 0;
	}
	//o que posicion le corresponde
	int count(int x) {
		// Elementos < {x+1, 0} menos elementos < {x, 0}
		return oset.order_of_key({x + 1, 0}) - oset.order_of_key({x, 0});
	}
	void erase_one(int x) {
		auto it = oset.lower_bound({x, 0});
		if (it != oset.end() && it->first == x) { oset.erase(it); }
	}
	//0 indexed
	int kth_element(int k) { return oset.find_by_order(k)->first; }
	
	void insert(int x){
		oset.insert({x, count++});
	}
};







//example:
signed main() {
	int counter = 0;  // Identificador único

	// Insertar elementos (pueden repetirse en el valor)
	oset.insert({3, counter++});
	oset.insert({5, counter++});
	oset.insert({3, counter++});
    oset.insert({3, counter++});

	for(int i = 0; i<(int)oset.size(); i++){
        cout<<kth_element(i)<<endl;
    }
    erase_one(5);
    cout<<"-------\n";
    for(int i = 0; i<(int)oset.size(); i++){
        cout<<kth_element(i)<<endl;
    }
}
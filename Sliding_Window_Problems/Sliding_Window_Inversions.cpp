#include<iostream>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
using namespace std;
using namespace __gnu_pbds;

#define int long

signed main() {
	int n, k, l = 0, r = 0;
	ordered_set w;
	cin >> n >> k;

	int arr[n];

	for(int &a: arr) cin >> a;

	for(int i = 0; i < n; i ++) {
		if(l == k) {
			auto x = w.order_of_key(arr[i-k]);
			r -= x;
			auto it = w.lower_bound(arr[i-k]-1);
			w.erase(it);
			l --;
		}
		r += w.size() - w.order_of_key(arr[i] + 1);
		w.insert(arr[i]);
		l ++;
		if(l == k) {
			cout << r << " ";
		}
	}
	cout << endl;
	return 0;
}	

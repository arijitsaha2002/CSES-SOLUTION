#include<iostream>
#include <map>
#include <set>
using namespace std;

#define int long

int arr[(int)(1e7+10)];

signed main() {
	int n, k, l = 0;
	map<int, int> w;
	set<pair<int, int>> counts;
	cin >> n >> k;
	int arr[n];
	for(int &a: arr) cin >> a;

	for(int i = 0; i < n; i ++) {
		if(l == k) {
			counts.erase({-w[arr[i-k]], arr[i-k]});
			w[arr[i-k]]--;
			if(w[arr[i-k]] > 0 ) counts.insert({-w[arr[i-k]], arr[i-k]});
			l --;
		}
		counts.erase({-w[arr[i]], arr[i]});
		w[arr[i]] ++;
		counts.insert({-w[arr[i]], arr[i]});
		l ++;
		if(l == k) {
			cout << counts.begin()->second << " ";
		}
	}
	cout << endl;
	return 0;
}	

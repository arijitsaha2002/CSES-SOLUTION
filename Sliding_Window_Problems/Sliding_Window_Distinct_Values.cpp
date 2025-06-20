#include<iostream>
#include <map>
using namespace std;

#define int long

int arr[(int)(1e7+10)];

signed main() {
	int n, k, l = 0;
	map<int, int> w;
	cin >> n >> k;
	int arr[n];
	for(int &a: arr) cin >> a;

	for(int i = 0; i < n; i ++) {
		if(l == k) {
			w[arr[i-k]]--;
			if(w[arr[i-k]] == 0) w.erase(arr[i-k]);
			l --;
		}
		w[arr[i]] ++;
		l ++;
		if(l == k) {
			cout << w.size() << " ";
		}
	}
	cout << endl;
	return 0;
}	

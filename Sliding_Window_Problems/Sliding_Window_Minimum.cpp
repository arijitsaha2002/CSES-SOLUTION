#include<iostream>
#include <deque>
using namespace std;

#define int long

int arr[(int)(1e7+10)];

signed main() {
	int n, k, r = 0, l = 0;
	deque<int> w;
	cin >> n >> k;
	int a, b, c;
	cin >> arr[0] >> a >> b >> c;
	for(int i = 0; i < n; i ++) {
		arr[i+1] = (arr[i]*a + b) % c;
		if(l == k) {
			if(w.front() == arr[i-k]) {
				w.pop_front();
			}
			l --;
		}
		while(w.size() and arr[i] < w.back()) {
			w.pop_back();
		}
		w.push_back(arr[i]);
		l ++;
		if(l == k) {
			r ^= w.front();
		}
	}
	cout << r << endl;
	return 0;
}	

#include<iostream>
using namespace std;

#define int long

int arr[(int)(1e7+10)];

signed main() {
	int n, k, r = 0, w = 0, l = 0;
	cin >> n >> k;
	int a, b, c;
	cin >> arr[0] >> a >> b >> c;
	w = arr[0];
	l = 1;
	for(int i = 1; i < n; i ++) {
		arr[i] = (arr[i-1]*a + b) % c;
		if(l < k) {
			w += arr[i];
			l ++;
		} else {
			w -= arr[i-k];
			w += arr[i];
		}
		if(l == k) {
			r ^= w;
		}
	}
	cout << r << endl;
	return 0;
}	

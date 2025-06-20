#include<iostream>
using namespace std;

#define int long

int arr[(int)(1e7+10)];

signed main() {
	int n, k, r = 0, w = 0, l = 0;
	cin >> n >> k;
	int a, b, c;
	cin >> arr[0] >> a >> b >> c;
	for(int i = 0; i < n; i ++) {
		arr[i+1] = (arr[i]*a + b) % c;
		if(l == k) {
			w ^= arr[i-k];
			l--;
		}
		w ^= arr[i];
		l++;
		if(l == k) {
			r ^= w;
		}
	}
	cout << r << endl;
	return 0;
}	

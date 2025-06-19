#include<iostream>
#include<map>
using namespace std;

#define int long
const int mod = 1e9+7;

signed main() {
	int n, x, result = 1;
	cin >> n;
	map<int, int> counts;
	for(int i=0; i<n; i++){
		cin >> x;
		counts[x]++;
	}
	for(auto c:counts) {
		result = (result * (c.second + 1)) % mod;
	}
	cout << result - 1 << endl;
	return 0;
}	

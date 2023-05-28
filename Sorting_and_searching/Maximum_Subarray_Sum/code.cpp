#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long n;
	cin >> n;
	vector<long> A(n);

	for_each(A.begin(), A.end(), [&](long & a) {cin >> a;});


	long long maxValue = A[0] , sum = 0;

	for (long i = 0; i < n; i++) {
		sum += A[i];
		maxValue = max(maxValue, sum);
		sum = max((long long)0, sum);
	}

	cout << maxValue << "\n";

	return 0;
}

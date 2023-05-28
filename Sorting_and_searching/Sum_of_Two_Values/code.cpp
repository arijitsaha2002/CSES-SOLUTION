#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Entry {
public:
	long value, index;
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	long n, s;
	cin >> n >> s;
	vector<Entry> A(n);
	long i, j;

	for (i = 0; i < n; i++) {
		cin >> A[i].value;
		A[i].index = i;
	}

	sort(A.begin(), A.end(), [&](Entry & e1, Entry & e2) {return e1.value < e2.value;});

	i = 0, j = n - 1;

	while (i < j) {
		if (A[i].value + A[j].value == s) {
			cout << min(A[i].index, A[j].index) + 1 << " " << max(A[i].index, A[j].index) + 1 << "\n";
			return 0;
		}
		i += (A[i].value + A[j].value < s);
		j -= (A[i].value + A[j].value > s);
	}

	cout << "IMPOSSIBLE \n";

	return 0;
}

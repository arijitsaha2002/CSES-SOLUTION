#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


long long  findIndex(vector<int> &A, long long int value) {
	long long  leftIndex = 0, rightIndex = A.size() - 1, midIndex = (leftIndex + rightIndex) / 2;
	if (A[rightIndex] <= value) return rightIndex;
	do {
		if (value < A[midIndex]) rightIndex = midIndex;
		else leftIndex = midIndex;
		midIndex = (rightIndex + leftIndex) / 2;

	} while (midIndex != leftIndex);
	return leftIndex;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long  tickets, customer;
	cin >> tickets >> customer;

	vector<int> T(tickets);
	vector<long long int> C(customer);

	for (long long  i = 0; i < tickets; i++) {
		cin >> T[i];
	}
	for (long long  i = 0; i < customer; i++) {
		cin >> C[i];
	}

	for (auto c : C) {

		if (T.size() == 0 and T[0] < c) cout << -1 << endl;
		else {
			long  index = findIndex(T, c);
			cout << T[index] << endl;
			T.erase(T.begin() + index);
		}

	}
	return 0;
}
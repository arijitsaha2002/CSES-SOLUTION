#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Tickets {
public:
	long long int  tickets;
	bool isAvailable;
};


long long  findIndex(vector<Tickets> &A, long long int value) {
	long long  leftIndex = 0, rightIndex = A.size() - 1, midIndex = (leftIndex + rightIndex) / 2;
	if (A[rightIndex].tickets <= value) return rightIndex;
	do {
		if (value < A[midIndex].tickets) rightIndex = midIndex;
		else leftIndex = midIndex;
		midIndex = (rightIndex + leftIndex) / 2;

	} while (midIndex != leftIndex);
	return leftIndex;
}

bool isLess(Tickets &t1, Tickets &t2) {
	return t1.tickets < t2.tickets;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long  tickets, customer;
	cin >> tickets >> customer;

	vector<Tickets> T(tickets);
	vector<long long int> C(customer);

	for (long long  i = 0; i < tickets; i++) {
		cin >> T[i].tickets;
		T[i].isAvailable = true;
	}
	for (long long  i = 0; i < customer; i++) {
		cin >> C[i];
	}

	sort(T.begin(), T.end(), isLess);
	long lastIndex = -1, largeIndex = T.size() - 1;

	for (auto c : C) {

		long  index = findIndex(T, c);
		bool isDone = false;

		if (T[index].tickets <= c) {

			for (long  i = min(index, largeIndex); i > lastIndex; i --) {
				if (T[i].isAvailable) {
					cout << T[i].tickets << endl;
					T[i].isAvailable = false;
					isDone = true;
					if (lastIndex == i - 1) lastIndex ++;
					if (largeIndex == i + 1) largeIndex --;
					break;

				}
			}

		}

		if (not isDone) cout << -1 << endl;

	}

	return 0;

}

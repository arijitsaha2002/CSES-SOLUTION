#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool NextPos(vector<int> &A) {
	int findLeft = 0;
	for (; findLeft < 7; findLeft ++) {
		if (A[findLeft] > A[findLeft + 1]) {
			findLeft ++;
			int findRight = 0;
			while (findRight < findLeft) {
				if (A[findRight] > A[findLeft]) {
					break;
				}
				findRight ++;
			}
			swap(A[findLeft], A[findRight]);
			reverse(A.begin(), A.begin()  + findLeft);
			cout << "come" << endl;
			return true;
		}
	}
	return false;
}

int main() {

	vector<int> P(8);
	for (int l = 0; l < 8; l++) P[l] = 7 - l;
	for_each(P.begin(), P.end(), [](int a){cout << a << " ";});
	NextPos(P);
	for_each(P.begin(), P.end(), [](int a){cout << a << " ";});

	return 0;
}
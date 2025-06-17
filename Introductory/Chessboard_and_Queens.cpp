#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
bool Checker(vector<int> &A) {
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j ++) {
			if (A[i] == A[j]) return false;
			if (abs(A[i] - A[j]) == j - i) return false;
		}
	}
	return true;
}
 
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
			reverse(A.begin(), A.begin() + findLeft);
			return true;
		}
	}
	return false;
}
 
bool isBlocked(vector<vector<bool>> &Block , vector<int> P) {
	for (int i = 0; i < 8; i ++) {
		if (Block[i][P[i]]) return false;
	}
	return true;
}
 
int allPossible(vector<vector<bool>> &Block) {
	vector<int> P(8);
	for (int l = 0; l < 8; l++) P[l] = 7 - l;
	int i = 0;
	while (NextPos(P)) {
		if (Checker(P) and isBlocked(Block, P) ) i ++;
	}
	return i;
}
 
 
int main() {
 
	vector<vector<bool>> Block(8, vector<bool>(8, false));
	string s;
	for (int i = 0; i < 8 ; i ++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			Block[i][j] = (s[j] == '*');
		}
	}
 
	cout << allPossible(Block) << endl;
 
	return 0;
}

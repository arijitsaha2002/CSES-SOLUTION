#include <iostream>
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

void NextPos(vector<int> &A) {
	A[0] ++;
	for (int i = 0; i < A.size() - 1; i ++) {
		if (A[i] > 7) {
			A[i] = 0;
			A[i + 1] ++;
		}
	}
}

bool isBlocked(vector<vector<bool>> &Block , vector<int> P) {
	for (int i = 0; i < 8; i ++) {
		if (Block[i][P[i]]) return false;
	}
	return true;
}

int allPossible(vector<vector<bool>> &Block) {
	vector<int> P(8, 0);
	int i = 0;
	NextPos(P);
	while (P[7] < 8) {
		if (Checker(P) and isBlocked(Block, P) ) i ++;
		NextPos(P);
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

#include<iostream>
using namespace std;

int board[102][102];

int get_lowest_number(int x, int y) {
	int arr[x + y], is_present[x + y], s = 0;
	
	for(int i = 0; i < x; i ++) {
		is_present[s] = false;
		arr[s++] = board[i][y];
	}
	
	for(int i = 0; i < y; i ++) {
		is_present[s] = false;
		arr[s++] = board[x][i];
	}
	
	for(int i = 0; i < s; i ++) {
		if(arr[i] < s) {
			is_present[arr[i]] = true;
		}
	}
	for(int i = 0; i < s; i ++) {
		if(not is_present[i]) {
			return i;
		}
	}
	return s;
}

void solve(int n) {
	if(n == 1) {
		board[0][0] = 0;
		return;
	}

	solve(n - 1);
	
	for(int i = 0; i < n - 1; i ++) {
		board[n - 1][i] = get_lowest_number(n - 1, i);
		board[i][n - 1] = board[n - 1][i];
	}

	board[n-1][n-1] = 0;
}	

int main() {
	int n;
	cin >> n;
	solve(n);

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

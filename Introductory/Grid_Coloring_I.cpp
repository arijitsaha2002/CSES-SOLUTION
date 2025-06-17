#include<iostream>
using namespace std;

int n, m;
char board[502][502];

bool solve(int x, int y) {
	if(x > n) return true;
	else if(y > m) return solve(x + 1, 1);
	char original = board[x][y];
	for(char c = 'A'; c <= 'D'; c++) {
		if(c != original and c != board[x][y-1] and c != board[x-1][y]) {
			board[x][y] = c;
			if(solve(x, y+1)) return true;
		}
	}
	return false;
}


int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) {
			cin >> board[i][j];
		}
	}

	if(!solve(1, 1)) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}	

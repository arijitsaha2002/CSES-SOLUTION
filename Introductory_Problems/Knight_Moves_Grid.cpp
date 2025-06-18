#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	int moves[n][n];
	int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
    int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			moves[i][j] = INT_MAX;
		}
	}
	
	moves[0][0] = 0;
	queue<pair<int, int>> Q;
	Q.push({0, 0});

	while(Q.size()) {
		auto top = Q.front();
		Q.pop();
		int x = top.first, y = top.second;

		for (int i = 0; i < 8; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				if (moves[next_x][next_y] > moves[x][y] + 1) {
					moves[next_x][next_y] = moves[x][y] + 1;
					Q.push({next_x, next_y});
				}
			}
		}
	}

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cout << moves[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}	

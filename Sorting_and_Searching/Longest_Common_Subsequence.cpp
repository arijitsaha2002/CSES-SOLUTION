#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[1001][1001];
pair<int, int> trace[1001][1001];

int main() {
	int n, m, l;
	vector<pair<int,int>> matchings;
	cin >> n >> m;
	int a[n], b[m];
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	
	for(int x = 0; x < n; x ++) {
		for(int y = 0; y < m; y ++) {
			l = max(dp[x + 1][y], dp[x][y + 1]);
			
			if(dp[x+1][y] > dp[x][y + 1]) {
				trace[x+1][y+1] = trace[x+1][y];
			} else {
				trace[x+1][y+1] = trace[x][y+1];
			}

			dp[x+1][y+1] = max(l, dp[x][y] + (a[x] == b[y]));
			
			if(l != dp[x+1][y+1]) {
				trace[x+1][y+1] = make_pair(x+1, y+1);
			}
		}
	}
	int x=trace[n][m].first - 1, y=trace[n][m].second - 1;
	while(x>=0 and y>=0) {
		matchings.push_back({x, y});
		auto t = trace[x][y];
		x = t.first - 1;
		y = t.second - 1;
	}
	cout << matchings.size() << endl;
	reverse(matchings.begin(), matchings.end());

	for(auto p: matchings) {
		cout << a[p.first] << " ";
	}
	cout << endl;
	return 0;
}	

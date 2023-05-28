#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define Point pair<int, int>

Point A, B;
int n, m;

bool notVisited[1000][1000];

bool dfs(int x, int y,string s) {
    if (x == B.first and y == B.second) {
        return true;
    }
    notVisited[x][y] = false;
    bool r = false;
    if (x - 1 > -1 and notVisited[x - 1][y]) r = r or dfs(x - 1, y,s+"L");
    if (y - 1 > -1 and notVisited[x][y - 1]) r = r or dfs(x, y - 1,s+"U");
    if (x + 1 < n and notVisited[x + 1][y]) r = r or dfs(x + 1, y,s+"R");
    if (y + 1 < m and notVisited[x][y + 1]) r = r or dfs(x, y + 1,s+"D");
    return r;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    char c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            notVisited[i][j] = (c != '#');
            if (c == 'A') {
                A.first = i;
                A.second = j;
            }
            else if (c == 'B') {
                B.first = i;
                B.second = j;
            }
        }
    }

    if(not dfs(A.first, A.second,"")){
        cout << "NO\n";
    }

    return 0;
}
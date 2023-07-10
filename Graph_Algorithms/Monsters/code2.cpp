#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
vector<pair<int, int>> Monsters;
pair<int, int> Me;
char arr[1001][1001];
int gate[1001][1001];
Point parent[1001][1001];



void done(int x, int y) {
    queue<char> Path;

    while (parent[x][y].first != -1) {
        if (parent[x][y].first == x) {
            if (parent[x][y].second < y) {
                Path.push('L');
            }
            else {
                Path.push('R');
            }
        }
        else {
            if (parent[x][y].first < x) {
                Path.push('U');
            }
            else {
                Path.push('D');
            }
        }

        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    cout << "YES" << newline;
    cout << Path.size() << newline;
    for (; not Path.empty(); Path.pop()) {
        cout << Path.front();
    }
    cout << endl;
}

bool is_inside(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < m and arr[x][y] != '#');
}

bool is_gate(int x, int y) {
    return (x == 0 or y == 0 or x == n - 1 or y == m - 1);
}

void bfs(pair<int, int> gate) {

    if (arr[gate.first][gate.second] != '#' and arr[gate.first][gate.second] != 'M') {
        // cout << gate.first << blankChar << gate.second << endl;

        vector<vector<bool>> is_visited(n, vector<bool>(m, false));
        queue<pair<Point, int>> Q;
        Q.push(make_pair(gate, 0));

        int min_level = INT_MAX;
        parent[gate.first][gate.second] = make_pair(-1, -1);

        while (not Q.empty()) {
            auto top = Q.front();
            auto pos = top.first;
            auto level = top.second;
            Q.pop();
            is_visited[pos.first][pos.second] = true;

            if (arr[pos.first][pos.second] == 'M') {
                // cout << "Monsters " << pos.first << blankChar << pos.second << endl;
                return;
            }
            else if (arr[pos.first][pos.second] == 'A' and level < min_level) {
                done(pos.first, pos.second);
                exit(0);
            }

            for (int i = -1; i < 2; i ++) {
                for (int j = 1 - abs(i); j >= abs(i) - 1; j -= 2) {

                    int x = pos.first + i;
                    int y = pos.second + j;
                    if (is_inside(x, y) and not is_visited[x][y]) {
                        is_visited[x][y] = true;

                        if (arr[x][y] == 'M') {
                            min_level = min(min_level, level + 1);
                        }

                        parent[x][y] = pos;
                        Q.push(make_pair(make_pair(x, y), level + 1));
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i ++) {
        bfs(make_pair(i, 0));
        bfs(make_pair(i, m - 1));
    }

    for (int i = 1; i < m - 1; i ++) {
        bfs(make_pair(0, i));
        bfs(make_pair(n - 1, i));
    }

    cout << "NO" << endl;
    return 0;
}
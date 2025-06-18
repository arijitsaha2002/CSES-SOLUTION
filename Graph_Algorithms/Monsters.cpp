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
int dist[1001][1001];
Point parent[1001][1001];

void fill_gate() {
    for (int i = 0; i < 1001; i ++) {
        for (int j = 0; j < 1001; j++) {
            gate[i][j] = INT_MAX;
            dist[i][j] = INT_MAX;
        }
    }
}


bool is_inside(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < m and arr[x][y] != 'M' and arr[x][y] != '#');
}

bool is_gate(int x, int y) {
    return (x == 0 or y == 0 or x == n - 1 or y == m - 1);
}

void bfs() {
    vector<vector<bool>> is_visited(n, vector<bool>(m, false));

    queue<pair<Point, int>> Q;
    for (auto monster : Monsters) {
        is_visited[monster.first][monster.second] = true;
        Q.push(make_pair(monster, 0));
    }

    while (not Q.empty()) {
        auto top = Q.front();
        auto pos = top.first;
        auto level = top.second;
        Q.pop();
        is_visited[pos.first][pos.second] = true;

        if (is_gate(pos.first, pos.second)) {
            gate[pos.first][pos.second] = min(gate[pos.first][pos.second], level);
        }
        for (int i = -1; i < 2; i ++) {
            for (int j = 1 - abs(i); j >= abs(i) - 1; j -= 2) {

                int x = pos.first + i;
                int y = pos.second + j;
                if (is_inside(x, y) and not is_visited[x][y]) {
                    is_visited[x][y] = true;
                    Q.push(make_pair(make_pair(x, y), level + 1));
                }
            }
        }
    }
}

void done(int x, int y) {
    stack<char> Path;

    while (parent[x][y].first != -1) {
        if (parent[x][y].first == x) {
            if (parent[x][y].second < y) {
                Path.push('R');
            }
            else {
                Path.push('L');
            }
        }
        else {
            if (parent[x][y].first < x) {
                Path.push('D');
            }
            else {
                Path.push('U');
            }
        }

        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    cout << "YES" << newline;
    cout << Path.size() << newline;
    for (; not Path.empty(); Path.pop()) {
        cout << Path.top();
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill_gate();

    char c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            arr[i][j] = c;
            if (c == 'M') {
                Monsters.push_back({i, j});
            }
            else if (c == 'A') {
                Me = {i, j};
            }
        }
    }


    bfs();


    vector<vector<bool>> is_visited(n, vector<bool>(m, false));

    queue<pair<Point, int>> Q;
    Q.push(make_pair(Me, 0));
    parent[Me.first][Me.second] = { -1, -1};

    while (not Q.empty()) {
        auto top = Q.front();
        auto pos = top.first;
        auto level = top.second;

        Q.pop();
        is_visited[pos.first][pos.second] = true;

        if (is_gate(pos.first, pos.second)) {
            if (level < gate[pos.first][pos.second]) {
                done(pos.first, pos.second);
                return 0;
            }
        }

        else {
            for (int i = -1; i < 2; i ++) {

                for (int j = 1 - abs(i); j >= abs(i) - 1; j -= 2) {
                    int x = pos.first + i;
                    int y = pos.second + j;
                    if (is_inside(x, y) and not is_visited[x][y]) {
                        parent[x][y] = pos;
                        is_visited[x][y] = true;
                        Q.push(make_pair(make_pair(x, y), level + 1));
                    }
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
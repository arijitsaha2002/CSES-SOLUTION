#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


int n, m, k, a, b, t, s = 0;
const int MaxN = 1010;
vector<int> Nodes[MaxN];
int cp[MaxN][MaxN];
int Path[MaxN];


int bfs() {
    vector<bool> is_visited(MaxN, 0);
    queue<Point> Q;
    Q.push({0, 1e16});

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();
        is_visited[top.first] = true;

        for (auto adj : Nodes[top.first]) {
            if (not is_visited[adj] and cp[top.first][adj] > 0) {
                is_visited[adj] = true;
                Path[adj] = top.first;
                if (adj == t) {
                    return min(cp[top.first][adj], top.second);
                }
                Q.push({adj, min(cp[top.first][adj], top.second)});
            }
        }
    }

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    cin >> n >> m >> k;
    t = n + m + 1;

    for (int i = 1; i <= n; i++) {
        Nodes[0].push_back(i);
        cp[0][i] = 1;
    }

    for (int i = n + 1; i < t; i++) {
        Nodes[i].push_back(t);
        cp[i][t] = 1;
    }

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        if (cp[a][b + n] == 0) {
            Nodes[a].push_back(b + n);
            Nodes[b + n].push_back(a);
            cp[a][b + n] = 1;
        }
    }

    Path[0] = -1;
    int max_flow = 0;

    for (int aug = bfs(); aug; aug = bfs()) {
        max_flow += aug;

        int curr = t;
        while (curr != 0) {
            cp[Path[curr]][curr] -= aug;
            cp[curr][Path[curr]] += aug;
            curr = Path[curr];
        }
    }

    cout << max_flow << endl;

    for (int i = 1; i <= n; i ++) {
        for (auto adj : Nodes[i]) {
            if (cp[i][adj] == 0) {
                cout << i << blankChar << adj - n << newline;
            }
        }
    }
    return 0;
}
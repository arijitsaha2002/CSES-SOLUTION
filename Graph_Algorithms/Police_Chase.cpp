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

const int MaxN = 501;
int cap[MaxN][MaxN];
vector<int> Nodes[MaxN];
int parent[MaxN];
bool is_visited[MaxN];
int n, m, a, b, c = 1;
vector<Point> Edges;

int bfs() {
    fill(parent, parent + n + 1, 0);
    queue<Point> Q;
    Q.push({1, 1e18});

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : Nodes[top.first]) {
            if (parent[adj] == 0 and adj != 1 and cap[top.first][adj] != 0) {
                parent[adj] = top.first;
                if (adj == n) return min(cap[top.first][adj], top.second);
                Q.push({adj, min(cap[top.first][adj], top.second)});
            }
        }
    }
    return 0;
}

void bfs(int node) {
    is_visited[node] = true;
    for (auto adj : Nodes[node]) {
        if (not is_visited[adj] and cap[node][adj]) {
            bfs(adj);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        if (cap[a][b] == 0 and cap[b][a] == 0) {
            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }

        cap[a][b] += c;
        cap[b][a] += c;
    }

    parent[1] = 0;

    int arg, max_flow = 0;

    for (arg = bfs(); arg; arg = bfs()) {
        max_flow += arg;
        int curr = n;
        while (parent[curr] != 0) {
            cap[parent[curr]][curr] -= arg;
            cap[curr][parent[curr]] += arg;
            curr = parent[curr];
        }
    }

    bfs(1);

    cout << max_flow << endl;
    for (int i = 1; i <= n; i++) {
        if (is_visited[i]) {
            for (auto adj : Nodes[i]) {
                if (not is_visited[adj]) {
                    cout << i << blankChar << adj << newline;
                }
            }
        }
    }


    return 0;
}
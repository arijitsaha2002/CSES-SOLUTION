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

int n, m, a, b;
const int MaxN = 502;
int cap[MaxN][MaxN];
int is_vis[MaxN][MaxN];
bool act[MaxN][MaxN];
vector<int> Nodes[MaxN];
int Path[MaxN];
bool is_visited[MaxN];


int bfs() {
    vector<bool> is_visited(n + 1, false);
    queue<Point> Q;
    Q.push({1, 1e16});
    is_visited[1] = true;

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : Nodes[top.first]) {
            if (!is_visited[adj] and cap[top.first][adj]) {
                is_visited[adj] = true;
                Path[adj] = top.first;
                if (adj == n) return min(top.second, cap[top.first][adj]);
                Q.push({adj, min(top.second, cap[top.first][adj])});
            }
        }
    }

    return 0;
}

vector<int> p;
bool dfs(int node) {
    p.push_back(node);

    if (node == n) {
        cout << p.size() << newline;
        cout << p[0] << blankChar;
        for (int i = 1; i < p.size(); i++) {
            is_vis[p[i - 1]][p[i]] = true;
            cout << p[i] << blankChar;
        }
        is_visited[n] = false;
        is_visited[1] = false;
        cout << newline;
        p.pop_back();
        return true;
    }
    else {
        for (auto adj : Nodes[node]) {
            if (cap[node][adj] == 0 and act[node][adj] and not is_vis[node][adj]) {
                if (dfs(adj)) {
                    p.pop_back();
                    return true;
                }
            }
        }
    }
    p.pop_back();
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        if (!act[a][b] and !act[b][a]) {
            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }
        cap[a][b] += 1;
        act[a][b] = true;
    }


    int max_flow = 0;

    for (int aug = bfs(); aug; aug = bfs()) {
        max_flow += aug;
        int curr = n;
        while (curr != 1) {
            cap[Path[curr]][curr] -= aug;
            cap[curr][Path[curr]] += aug;
            curr = Path[curr];
        }
    }



    cout << max_flow << newline;

    // fill(is_visited, is_visited + MaxN, false);
    
    while (dfs(1)) {

    }
    return 0;
}
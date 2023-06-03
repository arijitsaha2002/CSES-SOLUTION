#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 1;
vector<int> Nodes[MaxN];
int team[MaxN];
bool is_visited[MaxN];

bool dfs(int n, int curr) {
    is_visited[n] = true;

    for (auto adj : Nodes[n]) {
        if (is_visited[adj]) {
            if (team[adj] != curr) {
                return false;
            }
        } else {
            team[adj] = curr;
            if (not dfs(adj, 1 - curr)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;

    FOR(i, 0, m) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    for (int i = 1; i < n; i++) {
        if (!is_visited[i]) {
            team[i] = 1;
            if (!dfs(i, 0)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << 2 - team[i] << blankchar;
    }
    cout << endl;

    return 0;
}
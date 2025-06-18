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
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, a, b, q;
const int MaxN = 1e5 + 2;
vector<pair<int, int>> Nodes[MaxN];
bool is_visited[(MaxN << 1) + 12];
vector<int> Path;

void dfs(pair<int, int> node) {
    is_visited[node.second] = true;
    while (not Nodes[node.first].empty() ) {
        auto adj = Nodes[node.first].back();
        Nodes[node.first].pop_back();
        if (not is_visited[adj.second]) {
            dfs(adj);
        }
    }

    if (Nodes[node.first].empty()) {
        Path.push_back(node.first);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < q; i ++) {
        cin >> a >> b;
        Nodes[a].push_back({b, i});
        Nodes[b].push_back({a, i});
    }

    for (int i = 1; i <= n; i++) {
        if (Nodes[i].size() & 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    dfs({1, q + 10});

    if (Path.size() != q + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }



    for (auto v : Path) {
        cout << v << blankChar;
    }
    cout << endl;

    return 0;
}
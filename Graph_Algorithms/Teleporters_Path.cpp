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


const int MaxN = 1e5 + 1;
vector<int> Nodes[MaxN];
vector<int> NodeRev[MaxN];
stack<int> Path;

void dfs(int node) {
    while (!Nodes[node].empty()) {
        auto adj = Nodes[node].back();
        Nodes[node].pop_back();
        dfs(adj);
    }

    Path.push(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        NodeRev[b].push_back(a);
    }

    if ((Nodes[1].size() != NodeRev[1].size() + 1 ) or (Nodes[n].size() != NodeRev[n].size() - 1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 2; i < n; i++) {
        if (Nodes[i].size() != NodeRev[i].size()) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    dfs(1);

    if (Path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    while (not Path.empty()) {
        cout << Path.top() << blankChar;
        Path.pop();
    }
    cout << endl;

    return 0;
}
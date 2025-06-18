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
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 2;
vector<int> Nodes[MaxN];
bool is_visited[MaxN];
bool is_bridge[MaxN];
int low[MaxN];
int Disc[MaxN];
int Parent[MaxN];
set<point> Ans;

int n, m, counter = 0;


void dfs(int node, int parent) {
    // cout << node << endl;
    is_visited[node] = true;
    Disc[node] = counter ++;
    low[node] = Disc[node];

    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            if (is_visited[adj]) {
                // cout << node << blankChar << adj << endl;
                low[node] = min(low[node], low[adj]);
            }
            else {
                dfs(adj, node);
                low[node] = min(low[node], low[adj]);
            }
        }
    }

    if(Disc[parent] < low[node] and parent != 0){
        Ans.insert({min(node, parent), max(node, parent)});
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m ; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    dfs(1, 0);

    cout << Ans.size() << newline;
    for (auto ans : Ans) {
        cout << ans.first << blankChar << ans.second << newline;
    }
    return 0;
}
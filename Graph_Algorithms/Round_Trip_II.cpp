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

const int MaxN = 1e5 + 10;
vector<vector<int>> Nodes(MaxN, vector<int>());
bool is_visited[MaxN];
bool in_path[MaxN];
stack<int> Path;

void dfs(int n) {

    if (in_path[n]) {
        string s = to_string(n);

        int length = 2;
        while (Path.top() != n) {
            length ++;
            s = to_string(Path.top()) + blankChar + s;
            Path.pop();
        }

        cout << length << newline;
        cout << to_string(n) << blankChar << s << endl;

        exit(0);
    }

    if (not is_visited[n]) {

        in_path[n] = true;
        is_visited[n] = true;
        Path.push(n);

        for (auto adj : Nodes[n]) {
            dfs(adj);
        }

        in_path[n] = false;
        Path.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (not is_visited[i]) {
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
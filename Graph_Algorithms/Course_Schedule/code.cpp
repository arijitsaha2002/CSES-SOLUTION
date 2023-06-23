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

const int MaxN = 1e5 + 4;
vector<vector<int>> Nodes(MaxN, vector<int>());
bool is_visited[MaxN];
bool is_returned[MaxN];
bool not_at_top[MaxN];

queue<int> Path;

void dfs(int n) {
    is_visited[n] = true;

    for (auto adj : Nodes[n]) {
        if (not is_visited[adj]) {
            dfs(adj);
        }
        else {
            if (not is_returned[adj]) {
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
        }
    }

    is_returned[n] = true;
    Path.push(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        Nodes[b].push_back(a);
        not_at_top[a] = true;
    }


    for (int i = 1; i <= n; i++) {
        if (not not_at_top[i]) {
            dfs(i);
        }
    }


    if (Path.size() != n) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    while (not Path.empty()) {
        cout << Path.front() << blankChar;
        Path.pop();
    }
    cout << endl;

    return 0;
}
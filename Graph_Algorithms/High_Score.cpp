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
#define Point pair<int, long>
#define ADD(a, b) ((a == LONG_MIN or b == LONG_MIN) ? LONG_MIN : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 25001;
vector<vector<Point>> Nodes(MaxN, vector<Point>());
vector<vector<int>> RevNodes(MaxN, vector<int>());
vector<long> Score(MaxN, LONG_MIN);
bool is_connected[MaxN];

void dfs(int n) {
    if (!is_connected[n]) {
        is_connected[n] = true;
        for (auto adj : RevNodes[n]) {
            dfs(adj);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Nodes[a].push_back({b, c});
        RevNodes[b].push_back(a);
    }

    dfs(n);

    Score[1] = 0;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto adj : Nodes[j]) {
                Score[adj.first] = max(Score[adj.first], ADD(Score[j], adj.second));
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (auto adj : Nodes[j]) {
            if (ADD(Score[j], adj.second) > Score[adj.first]) {
                if (is_connected[adj.first]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }


    cout << Score[n] << endl;
    return 0;
}
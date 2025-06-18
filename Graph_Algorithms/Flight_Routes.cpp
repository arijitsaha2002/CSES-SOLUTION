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
#define Point pair<int, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 2;
vector<Point> Nodes[MaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, m, k, a, b, c;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Nodes[a].push_back(make_pair(b, c));
    }

    vector<vector<int>> Dist(MaxN, vector<int>(k, 1e16));
    priority_queue<Point, vector<Point>, greater<Point>> Q;
    Q.push({0, 1});
    Dist[1][0] = 0;

    while (not Q.empty()) {
        auto top = Q.top();
        Q.pop();
        int dist = top.first;
        int node = top.second;

        if (dist <= Dist[node][k - 1] and dist != LONG_MAX) {
            for (auto adj : Nodes[node]) {
                if (Dist[adj.first][k - 1] > adj.second + dist) {
                    Dist[adj.first][k - 1] = adj.second + dist;
                    Q.push({adj.second + dist, adj.first});
                    sort(Dist[adj.first].begin(), Dist[adj.first].end());
                }
            }
        }

    }

    for (int i = 0; i < k; i ++) {
        cout << Dist[n][i] << blankChar;
    }
    cout << endl;

    return 0;
}
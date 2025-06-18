#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long long
#define MOD 1000000007
#define INF 1e16
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
const int MaxN = 1e5 + 4;
vector<point> Nodes[MaxN];
// vector<int> Parents[MaxN];
int ANS[MaxN][3];
int Dist[MaxN];

// tuple<int, int, int> dfs(int node) {
//     if (node == 1) return {1, 0, 0};
//     int result = 0, max_depth = -1, min_depth = INF;
//     for (auto adj : Parents[node]) {
//         auto ans = dfs(adj);
//         result += get<0>(ans);
//         result %= MOD;

//         max_depth = max(max_depth, get<1>(ans));
//         min_depth = min(min_depth, get<2>(ans));
//     }
//     return {result, max_depth + 1, min_depth + 1};
// }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Nodes[a].push_back(make_pair(b, c));
    }

    fill(Dist, Dist + MaxN, INF);
    set<point> Q;

    Q.insert(make_pair(0, 1));
    for (int i = 2; i <= n; i++) {
        Q.insert(make_pair(INF, i));
        ANS[i][0] = 0;
        ANS[i][1] = 0;
        ANS[i][2] = INF;
    }

    ANS[1][0] = 1;
    ANS[1][1] = 0;
    ANS[1][2] = 0;
    Dist[1] = 0;

    while (not Q.empty()) {
        auto top = Q.begin();
        int node = top->second;
        int d = top->first;

        if (Dist[node] == d) {
            for (auto adj : Nodes[node]) {
                if (adj.second + d < Dist[adj.first]) {
                    Dist[adj.first] = adj.second + d;
                    Q.insert(make_pair(adj.second + d, adj.first));
                    ANS[adj.first][0] = ANS[node][0];
                    ANS[adj.first][1] = ANS[node][1] + 1;
                    ANS[adj.first][2] = ANS[node][2] + 1;
                }
                else if (adj.second + d == Dist[adj.first]) {
                    // Q.insert(make_pair(adj.second + d, adj.first));
                    ANS[adj.first][0] += ANS[node][0];
                    ANS[adj.first][0] %= MOD;
                    ANS[adj.first][1] = max(ANS[adj.first][1], ANS[node][1] + 1);
                    ANS[adj.first][2] = min(ANS[adj.first][2], ANS[node][2] + 1);
                }
            }
        }
        Q.erase(Q.begin());
    }

    cout << Dist[n] << blankChar << ANS[n][0] << blankChar << ANS[n][2] << blankChar << ANS[n][1] << endl;
    return 0;
}
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
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 3e5;
const int Upper = 1e5;
vector<vector<Point>> Nodes(MaxN, vector<Point>());
int n, m;

long Price[MaxN];

void dijkstra() {
    set<Point> S;

    S.insert({0, 1});
    for (int i = 2; i <= 2 * n; i++) {
        S.insert({LONG_MAX, i});
    }

    while (not S.empty()) {
        auto top = S.begin();
        S.erase(top);

        long node = top->second;
        long price = top->first;

        if (Price[top->second] == 0) {
            Price[top->second] = top->first;
            for (auto adj : Nodes[node]) {
                if (Price[adj.first] == 0) {
                    S.insert({price + adj.second, adj.first});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    long a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Nodes[a].push_back({b, c});
        Nodes[a].push_back({b + n, (c / 2)});
        Nodes[a + n].push_back({b + n, c});
    }

    dijkstra();
    cout << Price[2 * n] << endl;
    return 0;
}
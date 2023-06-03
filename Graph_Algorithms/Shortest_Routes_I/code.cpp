#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<ll, ll>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 1;
vector<Point> Nodes[MaxN];
vector<ll> Dist(MaxN, LONG_LONG_MAX);
bool is_visited[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b, d;
    cin >> n >> m;

    FOR(i, 0, m) {
        cin >> a >> b >> d;
        Nodes[a].push_back({d, b});
    }

    priority_queue<Point, vector<Point>, greater<Point>> Heap;
    Heap.push({0, 1});
    is_visited[1] = true;

    while (!Heap.empty()) {
        auto top = Heap.top();
        Heap.pop();
        Dist[top.second] = min(top.first, Dist[top.second]);
        is_visited[top.second] = true;

        if (Dist[top.second] == top.first) {
            for (auto adj : Nodes[top.second]) {
                if (not is_visited[adj.second]) {
                    Heap.push({adj.first + top.first, adj.second});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Dist[i] << blankchar;
    }
    cout << endl;

    return 0;
}
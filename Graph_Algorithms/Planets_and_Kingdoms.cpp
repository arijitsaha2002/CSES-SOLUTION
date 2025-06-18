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
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 4;
vector<int> Nodes[MaxN];
vector<int> RevNodes[MaxN];
int root[MaxN];
int count_root[MaxN];
int counter = 0;

void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    root[node] = ++ counter;
    count_root[node] = 2;

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : Nodes[top]) {
            if (count_root[adj] < 2 and root[adj] != root[node]) {
                root[adj] = root[node];
                count_root[adj] = 1;
                Q.push(adj);
            }
        }
    }

    Q.push(node);

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : RevNodes[top]) {
            if (count_root[adj] == 1 and root[adj] == root[node]) {
                root[adj] = root[node];
                count_root[adj] = 2;
                Q.push(adj);
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        RevNodes[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (count_root[i] < 2) {
            bfs(i);
        }
    }


    cout << counter << newline;
    for(int i = 1; i <= n; i++){
        cout << root[i] << blankChar;
    }
    cout << endl;

    return 0;
}
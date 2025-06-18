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
int n, m;
set<int> Nodes[MaxN];
set<int> RevNodes[MaxN];
int Parent[MaxN];
int Coin[MaxN];
int Ans[MaxN];
bool is_visited[MaxN];

void dfs(int node) {
    int m = 0;
    is_visited[node] = true;

    for (auto adj : Nodes[node]) {
        if (not is_visited[adj]) {
            dfs(adj);
        }
        m = max(Ans[adj], m);
    }

    Ans[node] = m + Coin[node];
}

void Strongly_Connected(int node) {
    queue<int> Q;
    Parent[node] = node;
    Q.push(node);

    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : Nodes[top]) {
            if (Parent[adj] <= 0 and Parent[adj] != -node) {
                Parent[adj] = -node;
                Q.push(adj);
            }
        }
    }

    Q.push(node);
    while (not Q.empty()) {
        auto top = Q.front();
        Q.pop();

        for (auto adj : RevNodes[top]) {
            if (Parent[adj] == -node) {
                Parent[adj] = node;
                Coin[node] += Coin[adj];
                Q.push(adj);
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> Coin[i];

    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        Nodes[a].insert(b);
        RevNodes[b].insert(a);
    }


    for (int i = 1; i <= n; i ++) {
        if (Parent[i] <= 0) {
            Strongly_Connected(i);
        }
    }

    vector<int> NewNodes;

    for (int i = 1; i <= n; i ++) {
        if (Parent[i] == i) {
            NewNodes.push_back(i);
            vector<int> v;
            for (auto adj : Nodes[i]) {
                v.push_back(adj);
                Nodes[i].insert(Parent[adj]);
            }

            for (auto adj : v) {
                if (adj != Parent[adj]) Nodes[i].erase(adj);
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (Parent[i] != i) {
            for (auto adj : Nodes[i]) {
                Nodes[Parent[i]].insert(Parent[adj]);
            }
        }
    }


    for (auto p : NewNodes) {
        if (not is_visited[p]) {
            dfs(p);
        }
    }

    cout << *max_element(Ans + 1, Ans + n + 1) << endl;

    return 0;
}
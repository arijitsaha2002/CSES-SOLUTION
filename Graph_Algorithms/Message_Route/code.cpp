#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 1;
int parent[MaxN];
bool is_visited[MaxN];
vector<vector<int>> Nodes(MaxN, vector<int>());

void bfs(int n, int p) {
    queue<int> Q;
    Q.push(1);
    int curr = 1;
    is_visited[curr] = true;

    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();

        for (auto adj : Nodes[curr]) {
            if (!is_visited[adj]) {
                is_visited[adj] = true;
                parent[adj] = curr;
                Q.push(adj);
            }
        }
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
        Nodes[b].push_back(a);
    }

    bfs(1, 0);

    if (parent[n]) {
        stack<int> ST;
        int temp = n;

        while (temp) {
            ST.push(temp);
            temp = parent[temp];
        }
        cout << ST.size() << newline;
        while (!ST.empty()) {
            cout << ST.top() << blankchar;
            ST.pop();
        }
        cout << newline;

    } else {
        cout << "IMPOSSIBLE" << newline;
    }

    return 0;
}
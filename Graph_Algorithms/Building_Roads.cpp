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
bool is_visited[MaxN];
vector<vector<int>> Nodes(MaxN, vector<int>());

void bfs(int n) {
    is_visited[n] = true;

    for (auto adj : Nodes[n]) {
        if (not is_visited[adj]) {
            bfs(adj);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;



    for (int i = 1; i <= m; i ++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    int r = 0;
    vector<int> S;
    for (int i = 1; i <= n; i++) {
        if (not is_visited[i]) {
            S.push_back(i);
            r ++;
            bfs(i);
        }
    }

    cout << r - 1 << endl;
    for (int i = 1; i < S.size(); i++) {
        cout << S[0] << blankchar << S[i] << newline;
    }

    return 0;
}
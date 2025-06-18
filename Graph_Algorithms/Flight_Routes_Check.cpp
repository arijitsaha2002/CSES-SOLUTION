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

const int MaxN = 1e5 + 2;
int n, m, a, b;
vector<int> Nodes[MaxN];
vector<int> RevNodes[MaxN];
bool is_visited1[MaxN];
bool is_visited2[MaxN];
int counter = 0;

void dfs(int node, vector<int> *N, bool * is_visited) {
    is_visited[node] = true;
    counter ++;

    for (auto adj : N[node]) {
        if (not is_visited[adj]) dfs(adj, N, is_visited);
    }
}

void print_impossible(bool *is_visited) {
    cout << "NO" << endl;
    for(int i = 1; i <= n; i ++){
        if(not is_visited[i]){
            if(is_visited == is_visited1) cout << 1 << blankChar << i << endl;
            else cout << i << blankChar << 1 << endl;
            break;
        }
    }
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        RevNodes[b].push_back(a);
    }

    dfs(1, Nodes, is_visited1);
    if (counter != n) print_impossible(is_visited1);

    counter = 0;
    dfs(1, RevNodes, is_visited2);
    if (counter != n) print_impossible(is_visited2);

    cout << "YES" << endl;

    return 0;
}
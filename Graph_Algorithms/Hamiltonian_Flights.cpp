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

const int MaxN = 21;
vector<int> Nodes[MaxN];
bool is_visited[MaxN];
long dp[21][1 << 20];
bool is_done[21][1 << 20];
int n, m, a, b;

long dfs(int node, int c, int path){

    if(node == n){
        return (c == n);
    }

    if(is_done[node][path]){
        return dp[node][path];
    }

    is_visited[node] = true;

    long r = 0;
    for(auto adj : Nodes[node]){
        if(not is_visited[adj]){
            r += dfs(adj, c + 1, path | (1 << (adj - 1)));
        }
    }

    is_visited[node] = false;
    dp[node][path] = r % MOD;
    is_done[node][path] = true;
    return dp[node][path];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Nodes[a].push_back(b);
    }

    cout << dfs(1, 1, 1) << endl;
    return 0;
}
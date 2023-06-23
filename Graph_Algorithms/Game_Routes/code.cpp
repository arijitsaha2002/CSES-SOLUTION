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

const int MaxN = 1e5 + 4;
vector<int> Nodes[MaxN];
int n, m;

vector<long> dp(MaxN, -1);

long fill(int node) {
    if (node == n) return 1;

    if (dp[node] > -1) {
        return dp[node];
    }

    dp[node] = 0;

    for (auto adj : Nodes[node]) {
        dp[node] += fill(adj);
        dp[node] %= MOD;
    }

    return dp[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
    }

    cout << fill(1) << endl;
    return 0;
}
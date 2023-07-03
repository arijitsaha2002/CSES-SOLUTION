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

const int MaxN = 2e5 + 4;
vector<int> Nodes[MaxN];
int dp[MaxN][2];
bool is_done[MaxN][2];
bool is_visited[MaxN][2];

int recursive(int n, bool is_taken, int parent) {

    if (is_done[n][is_taken]) return dp[n][is_taken];

    int m = 0;
    for (auto adj : Nodes[n]) {
        if (adj != parent) {
            m += max(recursive(adj, 0, n), recursive(adj, 1, n));
        }
    }

    int final = m;

    if (is_taken) {
        for (auto adj : Nodes[n]) {
            if(adj != parent) {
                m -= max(recursive(adj, 0, n), recursive(adj, 1, n));
                m += recursive(adj, 0, n) + 1;

                final = max(final, m);

                m -= recursive(adj, 0, n) + 1;
                m += max(recursive(adj, 0, n), recursive(adj, 1, n));
            }
        }
    }

    dp[n][is_taken] = final;
    is_done[n][is_taken] = true;
    return final;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    cout << max(recursive(1, 0, 0), recursive(1, 1, 0)) << endl;

    return 0;
}
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
int dp[MaxN];

int dpFill(int n){
    if(dp[n]) return dp[n];

    for(auto adj : Nodes[n]){
        dp[n] += dpFill(adj);
    }

    return dp[n] + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    for(int i = 2; i <= n; i++){
        cin >> a;
        Nodes[a].push_back(i);
    }

    dpFill(1);

    for(int i = 1; i <= n; i++){
        cout << dp[i] << blankChar;
    }
    cout << endl;

    return 0;
}
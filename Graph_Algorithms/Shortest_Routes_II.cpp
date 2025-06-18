#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<ll, ll>
#define ADD(a, b) ((a == LONG_LONG_MAX or b == LONG_LONG_MAX) ? LONG_LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 501;
vector<vector<ll>> Dist(MaxN, vector<ll>(MaxN, LONG_LONG_MAX));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LONG_LONG_MAX));

    ll a, b, w;

    FOR(i, 0, m) {
        cin >> a >> b >> w;
        dp[a][b] = min(w, dp[a][b]);
        dp[b][a] = dp[a][b];
    }

    for(int i = 1; i <=n ; i++){
        dp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(ADD(dp[i][k], dp[k][j]), dp[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == LONG_LONG_MAX) {
                dp[i][j] = -1;
            }
        }
    }

    FOR(i, 0, q) {
        cin >> a >> b;
        cout << dp[a][b] << newline;
    }

    return 0;
}
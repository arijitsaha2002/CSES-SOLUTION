#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<ll, ll>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 2e6;
Point Best[(1 << 20)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    int W[n];
    INPUT(n, W);

    Best[0] = {1, 0};

    for (ll i = 1; i < (1 << n); i++) {
        Best[i] = {n + 1, 0};
        for (ll p = 0; p < n; p++) {
            if (i & (1 << p)) {
                Point t = Best[i ^ (1 << p)];
                if (t.second + W[p] <= m) {
                    t.second += W[p];
                } else {
                    t.first++;
                    t.second = W[p];
                }

                Best[i] = min(Best[i], t);
            }
        }
    }

    cout << Best[(1 << n) - 1].first << endl;

    return 0;
}
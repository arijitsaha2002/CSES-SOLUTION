#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)

int n, m;
const int MaxM = 1002, MaxN = 12;
vector<vector<int>> dp(MaxM, vector<int>((1 << MaxN), -1));

void get_masks(int i, int curr, int next, vector<int> &masks) {
    if (i == n + 1) masks.push_back(next);
    else {
        if (curr & (1 << i)) get_masks(i + 1, curr, next, masks);
        if ((curr & (1 << i)) == 0) get_masks(i + 1, curr, next | (1 << i), masks);
        if (i < n and (curr & (1 << i)) == 0 and (curr & (1 << (i + 1))) == 0) {
            get_masks(i + 2, curr, next, masks);
        }
    }
}

int solve(int col, int mask) {
    if (col == m + 1) return (mask == 0);
    if (dp[col][mask] != -1) return dp[col][mask];
    vector<int> masks;
    get_masks(1, mask, 0, masks);
    int ans = 0;
    for (auto next_mask : masks) {
        ans += solve(col + 1, next_mask);
        ans %= MOD;
    }
    dp[col][mask] = ans;
    masks.clear();
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);
    cin >> n >> m;
    cout << solve(1, 0) << endl;
    return 0;
}
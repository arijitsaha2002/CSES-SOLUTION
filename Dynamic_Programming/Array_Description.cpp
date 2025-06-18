#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;

long get_value(int first, int second, int length) {

    vector<vector<long>> dp(length + 1, vector<long>(m + 2, 0));

    if (first == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else {
        dp[0][first] = 1;
    }

    for (int i = 1; i <= length; i ++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    if (second == 0) {
        return accumulate(dp[length].begin(), dp[length].end(), 0LL) % MOD;
    }

    return dp[length][second];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] and arr[i - 1] and abs(arr[i] - arr[i - 1]) > 1) {
            cout << "0" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > m) {
            cout << "0" << endl;
            return 0;
        }
    }

    long result = 1;
    bool is_second = false;
    int index = 0;

    for (int i = 0; i < n; i ++) {
        if (arr[i] == 0) {
            if (not is_second) {
                is_second = true;
                index = i - 1;
            }
        }
        else {
            if (is_second) {
                if (index < 0) {
                    result *= get_value(0, arr[i], i);
                }
                else {
                    result *= get_value(arr[index], arr[i], i - index);
                }
                result %= MOD;
                is_second = false;
            }
        }
    }

    if (is_second) {
        if (index < 0) {
            result *= get_value(0, 0, n - 1);
        }
        else {
            result *= get_value(arr[index], 0, n - 1 - index);
        }
        result %= MOD;
    }

    cout << result << endl;
    return 0;
}
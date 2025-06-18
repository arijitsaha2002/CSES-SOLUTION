#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    long dp[s];

    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    dp[0] = 1;

    for (int i = 1; i <= s; i++) {
        long r = 0;
        for (int j = 0; j < n and i >= arr[j]; j++) {
            r += dp[i - arr[j]];
        }
        dp[i] = r;
        dp[i] %= M;
    }

    cout << dp[s] << endl;

    return 0;
}
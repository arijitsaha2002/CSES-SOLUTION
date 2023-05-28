#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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

    vector<int> dp(s + 1, s + 1);

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if ( arr[i] <= s ) dp[arr[i]] = 1;
    }

    sort(arr, arr + n);

    dp[0] = 0;

    for (int i = 1; i <= s; i++) {
        int min_value = dp[i];
        for (int j = 0; (j < n) and (i > arr[j]); j++) {
            min_value = min(min_value, 1 + dp[i - arr[j]]);
        }
        dp[i] = min_value;
    }

    cout << ((dp[s] == s + 1) ? -1 : dp[s]) << endl;

    return 0;
}
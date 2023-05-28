#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int dp[501][501];

int getValue(int a, int b) {
    if(a > b) swap(a, b);
    if (a == b) return 0;
    else if(dp[a][b]) return dp[a][b];
    else {
        int min_value = INT_MAX;
        for (int i = 1; i <= a / 2; i++) {
            min_value = min(min_value, getValue(a - i, b) + getValue(i, b) + 1);
        }
        for (int i = 1; i <= b / 2; i++) {
            min_value = min(min_value, getValue(a, b - i) + getValue(a, i) + 1);
        }
        dp[a][b] = min_value;
        return min_value;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << getValue(a, b) << endl;

    return 0;
}
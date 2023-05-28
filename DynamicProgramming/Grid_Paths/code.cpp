#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define ll long long
#define M 1000000007
#define newline ' '
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int dp[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string t;

    FOR(i, n) {
        cin >> t;
        FOR(j,n){
            if (t[j] != '*') {
                dp[i][j] = 1;
            }
        }
    }

    if(!dp[n-1][n-1]){
        cout << 0 << endl;
        return 0;
    }

    dp[n - 1][n - 1] = 1;


    int i = n - 1;
    while (i > -1 and dp[i][n - 1]) i--;
    while (i > -1) dp[i--][n - 1] = 0;


    int j = n - 1;
    while (j > -1 and dp[n - 1][j]) j--;
    while (j > -1) dp[n - 1][j--] = 0;

    for (i = n - 2; i > -1; i--) {
        for (j = n - 2; j > -1; j--) {
            if (dp[i][j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % M;
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}
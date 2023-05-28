#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
const int max_n = 1000001;
long dp[2][max_n];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, k;
    cin >> n >> k;

    long coins[n + 1];
    coins[0] = 0;

    for (int i = 1; i <= n; i++) cin >> coins[i];

    sort(coins, coins + n + 1);


    dp[0][0] = 1;


    for (int l = 1; l <= n; l++) {

        int i = l & 1, p = 1 - i;

        dp[i][0] = 1;

        for (int j = 1; j <= k and j < coins[l]; j++) {
            dp[i][j] = dp[p][j];
        }

        for (int j = coins[l]; j <= k; j++) {
            dp[i][j] = dp[p][j];
            dp[i][j] += dp[i][j - coins[l]];
            dp[i][j] %= M;
        }

    }

    cout << dp[n&1][k] << endl;

    return 0;
}
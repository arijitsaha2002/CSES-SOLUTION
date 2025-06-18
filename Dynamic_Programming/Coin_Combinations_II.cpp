#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
const int max_n = 1000001;
long dp[max_n];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, k;
    cin >> n >> k;

    long coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins, coins + n);

    dp[0] = 1;


    for (int l = 0; l < n; l++) {
        for (int j = coins[l]; j <= k; j++) {
            dp[j] += dp[j - coins[l]];
            dp[j] %= M;
        }
    }

    cout << dp[k] << endl;

    return 0;
}
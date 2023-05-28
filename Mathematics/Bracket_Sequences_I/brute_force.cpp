#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n&1){
        cout << 0 << newline;
        return 0;
    }

    n >>= 1;

    long dp[n + 1];
    dp [0] = 1;

    for (int i = 1; i <= n; i++) {

        long r = 0;
        for (int j = 0; j < i; j++) {
            r += (dp[j] * dp[i - j - 1]) % M;
            r %= M;
        }

        dp[i] = r;

    }

    cout << dp[n] << newline;

    return 0;
}
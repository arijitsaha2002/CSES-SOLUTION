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
#define ODD(n) (n & 1)
#define EVEN(n) ((n & 1) == 0)

const int max_n = 2 * 1e6;
ll dp[max_n];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = ((n * (n + 1)) >> 1);

    if (ODD(sum)) {
        cout << 0 << endl;
        return 0;
    }

    sum >>= 1;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= M;
        }
    }

    cout << (dp[sum] * ((M + 1) >> 1)) % M << endl;

    return 0;
}
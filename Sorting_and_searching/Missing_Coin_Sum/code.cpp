#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;
    vector<long> Coins(n);
    for_each(Coins.begin(), Coins.end(), [](long & a) {cin >> a;});
    long long sum = accumulate(Coins.begin(), Coins.end(), 0LL);
    sort(Coins.begin(), Coins.end());
    vector<vector<bool>> Table(n, vector<bool>(sum + 1, false));

    Table[0][Coins[0]] = 1;


    for (long i = 1; i < n; i++) {
        Table[i][Coins[i]] = 1;

        for (long j = 1; j <= sum; j++) {
            Table[i][Table[i - 1][j] * (j + Coins[i])] = 1;

        }

    }

    for (long j = 1; j <= sum; j ++) {
        for (long i = 0 ; i < n; i++) {
            if (not Table[i][j]) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }

    return 0;
}

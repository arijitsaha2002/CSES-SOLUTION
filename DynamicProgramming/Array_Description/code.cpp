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

long getValue(int a, int b, int n, int m) {
    n++;

    vector<vector<long>> c(n + 1, vector<long>(m + 1, (b == 0)));
    c[n][b] = 1;

    for (int i = n - 1; i >= 0; i--) {
        c[i][1] = (c[i + 1][1] + c[i + 1][2]) % M;

        for (int j = m - 1; j > 1; j--) {
            c[i][j] = (c[i + 1][j - 1] + c[i + 1][j] + c[i + 1][j + 1]) % M;
        }

        c[i][m] = (c[i + 1][m] + c[i + 1][m - 1]) % M;
    }

    if (a == 0) return accumulate(c[0].begin() + 1, c[0].begin() + m + 1, 0LL) % M;
    return c[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];

    FOR(i, n) cin >> arr[i];

    if (n == 1) {
        cout << (arr[0] ? 1 : m) << endl;
        return 0;
    }

    long r = 1, t;

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            int j = i;
            while (j < n - 1 and arr[j] == 0) j++;
            t = getValue(arr[i - 1], arr[j], j - i, m);
            r *= t;
            r %= M;
            i = j;
        } else if (arr[i - 1] and abs(arr[i] - arr[i - 1]) > 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << r << endl;

    return 0;
}
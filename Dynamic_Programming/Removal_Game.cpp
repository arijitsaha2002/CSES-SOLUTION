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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll arr[n];
    FOR(i, n) cin >> arr[i];

    ll sum = accumulate(arr, arr + n, 0LL);

    ll move[2][n];

    for (int i = n - 1; i > -1; i--) {
        move[i & 1][i] = arr[i];
        for (int j = i + 1; j < n; j++) {
            move[i & 1][j] = max(arr[i] - move[(i + 1) & 1][j], arr[j] - move[i & 1][j - 1]);
        }
    }

    cout << ((sum + move[0][n - 1]) >> 1) << endl;
    return 0;
}
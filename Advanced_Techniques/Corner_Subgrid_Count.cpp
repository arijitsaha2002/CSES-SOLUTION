#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define N 3000
bitset<N> arr[N];

int count_box(bitset<N> &a, bitset<N> &b) {
    int m = (a & b).count();
    return (m * (m - 1));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;

    for (int i = 0 ; i < n; i ++) {
        cin >> arr[i];
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            result += count_box(arr[i], arr[j]);
        }
    }

    cout << (result >> 1);
    return 0;
}
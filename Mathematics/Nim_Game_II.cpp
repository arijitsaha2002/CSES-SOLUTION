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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, r, testCase;
    cin >> testCase;

    while (testCase--) {
        r = 0;
        cin >> n;
        while (n--) {
            cin >> t;
            t &= 3;
            r ^= t;
        }

        if (r) cout << "first" << newline;
        else cout << "second" << newline;
    }

    return 0;
}
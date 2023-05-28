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

int getValue(int a, int b) {
    if (a == b) return 0;
    else {
        return 1 + getValue(max(a, b) - min(a, b), min(a, b));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    cin >> a >> b;
    cout << getValue(a, b) << endl;

    return 0;
}
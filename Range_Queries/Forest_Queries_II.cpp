#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankChar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
int Tree[1001][1001];
int n;

void update(int x, int y, int val) {
    for (; x <= n; x += (x & (-x))) {
        for (int i = y; i <= n; i += (i & (-i))) { Tree[x][i] += val; }
    }
}

int query(int x1, int y1, int x2, int y2) {
    int ans = 0;
    for (int i = x2; i; i -= (i & (-i))) {
        for (int j = y2; j; j -= (j & (-j))) { ans += Tree[i][j]; }
    }
    for (int i = x2; i; i -= (i & (-i))) {
        for (int j = y1 - 1; j; j -= (j & (-j))) { ans -= Tree[i][j]; }
    }
    for (int i = x1 - 1; i; i -= (i & (-i))) {
        for (int j = y2; j; j -= (j & (-j))) { ans -= Tree[i][j]; }
    }
    for (int i = x1 - 1; i; i -= (i & (-i))) {
        for (int j = y1 - 1; j; j -= (j & (-j))) { ans += Tree[i][j]; }
    }
    return ans;
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '*') update(j, i, 1);
        }
        
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> y >> x;
            if (query(x, y, x, y)) update(x, y, -1);
            else update(x, y, 1);
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << query(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}
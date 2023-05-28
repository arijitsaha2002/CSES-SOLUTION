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

const int MaxN = 6e6;
int tree[MaxN];
int n, m;

void build(int node, vector<vector<bool>> &arr, int x1, int y1, int x2, int y2) {
    if (x1 == x2 and y1 == y2) {
        tree[node] = arr[x1][y2];
    } else if (x1 <= x2 and y1 <= y2) {
        int child = node << 1;
        if (x2 - x1 > y2 - y1) {
            int mid = (x1 + x2) >> 1;
            build(child, arr, x1, y1, mid, y2);
            build(child + 1, arr, mid + 1, y1, x2, y2);
        } else {
            int mid = (y1 + y2) >> 1;
            build(child, arr, x1, y1, x2, mid);
            build(child + 1, arr, x1, mid + 1, x2, y2);
        }
        tree[node] = tree[child] + tree[child + 1];
    }
}

int queries(int node, int x1, int y1, int x2, int y2, int p1, int q1, int p2, int q2) {
    if (x1 > p2 or y1 > q2 or p1 > x2 or q1 > y2) {
        return 0;
    } 
    else if(x1 >= p1 and y1 >= q1 and x2 <= p2 and y2 <= q2){
        return tree[node];
    }
    else if (x1 <= x2 and y1 <= y2) {
        int child = node << 1;
        if (x2 - x1 > y2 - y1) {
            int mid = (x1 + x2) >> 1;
            int t1 = queries(child, x1, y1, mid, y2, p1, q1, p2, q2);
            int t2 = queries(child + 1, mid + 1, y1, x2, y2, p1, q1, p2, q2);
            return t1 + t2;
        } else {
            int mid = (y1 + y2) >> 1;
            int t1 = queries(child, x1, y1, x2, mid, p1, q1, p2, q2);
            int t2 = queries(child + 1, x1, mid + 1, x2, y2, p1, q1, p2, q2);
            return t1 + t2;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<bool>> arr(n, vector<bool>(n));

    char c;

    FOR(i, n) {
        FOR(j, n) {
            cin >> c;
            arr[i][j] = (c == '*');
        }
    }

    build(1, arr, 0, 0, n - 1, n - 1);
    int a, b, d, e;

    while(m --){
        cin >> a >> b >> d >> e;
        a --, b --, d --, e --;
        cout << queries(1, 0, 0, n - 1, n - 1, a, b, d, e) << newline;
    }

    return 0;
}
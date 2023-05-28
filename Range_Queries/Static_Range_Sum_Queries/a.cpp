#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr)             \
    for (int i = 0; i < N; i++) { \
        cin >> arr[i];            \
    }
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int Max_Size = 6e6;

ll tree[Max_Size];

void build(int node, int *arr, int low, int high) {
    if (low == high) tree[node] = arr[low];
    else if (low < high) {
        int mid = (low + high) >> 1;
        int next_node = (node << 1);
        build(next_node, arr, low, mid);
        build(next_node + 1, arr, mid + 1, high);

        tree[node] = tree[next_node] + tree[next_node + 1];
    }
}

ll queries(int node, int low, int high, int left, int right) {
    if (left <= low and right >= high) return tree[node];
    if (right < low or left > high) return 0;

    int mid = (low + high) >> 1;
    int next_node = (node << 1);

    ll ql = queries(next_node, low, mid, left, right);
    ll qr = queries(next_node + 1, mid + 1, high, left, right);

    return ql + qr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int arr[n];
    INPUT(n, arr);

    build(1, arr, 0, n - 1);

    int a, b;

    while (m--) {
        cin >> a >> b;
        a--, b--;
        cout << queries(1, 0, n - 1, a, b) << newline;
    }

    return 0;
}
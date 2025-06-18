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

int tree[(int)6e6];

void build(int node, int *arr, int low, int high) {
    if (low == high) {
        tree[node] = arr[low];
    } else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(child, arr, low, mid);
        build(child + 1, arr, mid + 1, high);
        tree[node] = max(tree[child], tree[child + 1]);
    }
}

int queries(int node, int low, int high, int value) {
    if (low <= high) {
        if (value > tree[node]) {
            return -1;
        }
        else if (low == high) {
            tree[node] -= value;
            return low;

        } else if (low < high) {
            int mid = (low + high) >> 1;
            int child = node << 1;
            int tl = queries(child, low, mid, value);
            if(tl == -1) tl = queries(child + 1, mid + 1, high, value);
            tree[node] = max(tree[child], tree[child + 1]);
            return tl;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];
    INPUT(n, arr);

    build(1, arr, 0, n - 1);

    int a;
    while (m--) {
        cin >> a;
        cout << queries(1, 0, n - 1, a) + 1<< blankchar;
    }
    cout << newline;

    return 0;
}
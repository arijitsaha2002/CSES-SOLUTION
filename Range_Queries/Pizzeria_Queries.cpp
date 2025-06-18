#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 8e5;
int left_tree[MaxN], right_tree[MaxN];

void build(int* tree, int node, int* arr, int low, int high) {
    if (low == high) {
        tree[node] = arr[low];
    } else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(tree, child, arr, low, mid);
        build(tree, child + 1, arr, mid + 1, high);
        tree[node] = min(tree[child], tree[child + 1]);
    }
}

int queries(int* tree, int node, int low, int high, int left, int right) {
    if (left <= low and high <= right) {
        return tree[node];
    } else if (right < low or high < left) {
        return INT_MAX;
    } else {
        int mid = (low + high) >> 1;
        int child = node << 1;
        int ql = queries(tree, child, low, mid, left, right);
        int qr = queries(tree, child + 1, mid + 1, high, left, right);
        return min(ql, qr);
    }
}

void update(int* tree, int node, int low, int high, int index, int value) {
    if (low == high) {
        if(low == index){
            tree[node] = value;
        }
    } else if (low <= index and index <= high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        update(tree, child, low, mid, index, value);
        update(tree, child + 1, mid + 1, high, index, value);
        tree[node] = min(tree[child], tree[child + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, t;
    cin >> n >> k;

    int R[n], L[n];
    for (int i = 0; i < n; i++) {
        cin >> t;
        R[i] = t + i + 1;
        L[i] = t - i - 1;
    }

    build(left_tree, 1, L, 0, n - 1);
    build(right_tree, 1, R, 0, n - 1);

    int a, b;
    while(k --){
        cin >> t;
        if(t == 1){
            cin >> a >> b;
            a --;
            update(left_tree, 1, 0, n - 1, a, b - a - 1);
            update(right_tree, 1, 0, n - 1, a, b + a + 1);
        }
        else{
            cin >> a;
            a --;
            int ql = queries(left_tree, 1, 0, n - 1, 0, a) + a + 1;
            int qr = queries(right_tree, 1, 0, n - 1, a, n - 1) - a - 1;
            cout << min(ql , qr) << newline;

        }
    }

    return 0;
}
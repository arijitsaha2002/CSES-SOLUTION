#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<long long, long long>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
const int MaxN = 1e6;
Point tree[MaxN];


void build(ll node, ll *arr, int low, int high) {
    if (low == high) {
        tree[node].first = arr[low];
        tree[node].second = arr[low];
    }
    else if (low < high) {
        ll mid = (low + high) >> 1;
        ll child = node << 1;
        build(child, arr, low, mid);
        build(child + 1, arr, mid + 1, high);
        tree[node].first = tree[child].first + tree[child + 1].first;
        tree[node].second = max(tree[child].second, tree[child].first + tree[child + 1].second);
    }
}

Point queries(int node, int left, int right, int low, int high) {
    if (left <= low and high <= right) {
        return tree[node];
    }
    else if (right < low or high < left) {
        return {0, 0};
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        Point ql = queries(child, left, right, low, mid);
        Point qr = queries(child + 1, left, right, mid + 1, high);
        if (qr.second + ql.first >= ql.second) {
            return {qr.first + ql.first, qr.second + ql.first};
        }
        else {
            return {qr.first + ql.first, ql.second};
        }
    }
    return {0, 0};
}


void update(int node, int low, int high, int index, int value) {
    if (low == high) {
        if (low == index) {
            tree[node].first = tree[node].second = value;
        }
    }
    else if (low <= index and index <= high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        update(child, low, mid, index, value);
        update(child + 1, mid + 1, high, index, value);
        tree[node].first = tree[child].first + tree[child + 1].first;
        tree[node].second = max( max(tree[child].second, tree[child].first + tree[child + 1].second) , 0LL);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll arr[n];
    INPUT(n, arr);
    build(1, arr, 0, n - 1);

    int a, b, t;
    while (m --) {
        cin >> t >> a >> b;
        if (t == 1) {
            a --;
            update(1, 0, n - 1, a, b);
        }
        else {
            Point r = queries(1, a - 1, b - 1, 0, n - 1);
            cout << max(r.second, 0LL) << newline;
        }
    }  
    return 0;
}
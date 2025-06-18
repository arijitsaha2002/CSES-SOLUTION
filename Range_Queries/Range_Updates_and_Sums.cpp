#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
const int MaxN = 2e5 + 2;
int Tree[MaxN << 3];
int Lazy[MaxN << 3];
int TreeSize[MaxN << 3];
int arr[MaxN];

void update_node(int node) {
    if (Lazy[node] < 0) {
        Tree[node] = -Lazy[node] * TreeSize[node];
    }
    else Tree[node] += Lazy[node] * TreeSize[node];
}

void push_updates(int node) {
    if (Lazy[node]) {
        int child = 2 * node;
        if (Lazy[node] < 0) {
            Lazy[child] = Lazy[node];
            Lazy[child + 1] = Lazy[node];
        }
        else {
            if (Lazy[child] < 0) Lazy[child] -= Lazy[node];
            else Lazy[child] += Lazy[node];

            if (Lazy[child + 1] < 0) Lazy[child + 1] -= Lazy[node];
            else Lazy[child + 1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}

void build(int node, int low, int high) {
    if (low == high) {
        Tree[node] = arr[low];
        TreeSize[node] = 1;
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(child, low, mid);
        build(child + 1, mid + 1, high);
        Tree[node] = Tree[child] + Tree[child + 1];
        TreeSize[node] = TreeSize[child] + TreeSize[child + 1];
    }
}

void update(int node, int low, int high, int left, int right, int value) {
    if (low <= high) {
        if (Lazy[node]) {
            update_node(node);
            push_updates(node);
        }

        if (left <= low and high <= right and low <= high) {
            Lazy[node] = value;
            update_node(node);
            push_updates(node);
        }
        else if (high < left or right < low) {
            return;
        }
        else if (low < high) {
            int mid = (low + high) >> 1;
            int child = node << 1;
            update(child, low, mid, left, right, value);
            update(child + 1, mid + 1, high, left, right, value);
            Tree[node] = Tree[child] + Tree[child + 1];
        }
    }
}

int queries(int node, int low, int high, int left, int right) {
    update_node(node);
    push_updates(node);

    if (left <= low and high <= right) {
        return Tree[node];
    }
    else if (high < left or right < low) {
        return 0;
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        int ql = queries(child, low, mid, left, right);
        int qr = queries(child + 1, mid + 1, high, left, right);
        return ql + qr;
    }
    return 0;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    INPUT(n, arr);

    int t, a, b, x;
    build(1, 0, n - 1);

    while (m --) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, x);
        }
        else if (t == 2) {
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, -x);
        }
        else if (t == 3) {
            cin >> a >> b;
            cout << queries(1, 0, n - 1, a - 1, b - 1) << newline;
        }
    }

    return 0;
}
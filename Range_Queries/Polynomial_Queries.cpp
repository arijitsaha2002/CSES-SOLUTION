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

const int MaxN = 2e5 + 4;
int Tree[MaxN << 2];
point Lazy[MaxN << 2];

void build(int node, int low, int high, int * arr) {
    if (low == high) {
        Tree[node] = arr[low];
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = 2 * node;
        build(child, low, mid, arr);
        build(child + 1, mid + 1, high, arr);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

void push_update(int node, int low, int high) {
    int child = node << 1;
    Tree[node] += (Lazy[node].first + Lazy[node].second) * (high - low + 1) / 2;

    if (high > low) {
        int slope = (Lazy[node].second - Lazy[node].first) / (high - low);
        int mid = (low + high) >> 1;

        Lazy[child].first += Lazy[node].first;
        Lazy[child].second += (Lazy[node].first + slope * (mid - low));

        if (mid + 1 >= low) {
            Lazy[child + 1].first += (Lazy[node].first + slope * (mid + 1 - low));
            Lazy[child + 1].second += Lazy[node].second;
        }

    }

    Lazy[node] = {0, 0};
}

void update(int node, int low, int high, int left, int right) {
    push_update(node, low, high);
    if (left <= low and high <= right) {
        Lazy[node].first = low - left + 1;
        Lazy[node].second = high - left + 1;
        push_update(node, low, high);
    }
    else if (right < low or high < left) {
        return;
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        update(child, low, mid, left, right);
        update(child + 1, mid + 1, high, left, right);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

int queries(int node, int low, int high, int left, int right) {
    push_update(node, low, high);
    if (left <= low and high <= right) {
        return Tree[node];
    }
    else if (right < low or high < left) {
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

    int n, q, a, b, t;
    cin >> n >> q;

    int arr[n];
    INPUT(n, arr);
    build(1, 0, n - 1, arr);

    while (q --) {
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 0, n - 1, a - 1, b - 1);
        }
        else {
            cout << queries(1, 0, n - 1, a - 1, b - 1) << newline;
        }

    }

    return 0;
}
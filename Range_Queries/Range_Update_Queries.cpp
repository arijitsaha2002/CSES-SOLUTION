#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) \
    for (int i = 0; i < N; i++) cin >> arr[i];
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll tree[(int)(6e6)];

void build(int node, long arr[], int low, int high) {
    if (low == high) {
        tree[node] = 0;
    } else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(child, arr, low, mid);
        build(child + 1, arr, mid + 1, high);
        tree[node] = tree[child] + tree[child + 1];
    }
}

ll queries(int node, int index, int low, int high) {
    if(low == high){
        if(index == low) return tree[node];
    }
    else if( index <= high and index >= low){
        int mid = (low + high) >> 1;
        int child = node << 1;
        ll ql = queries(child, index, low, mid);
        ll qr = queries(child + 1, index, mid + 1, high);
        return ql + qr + tree[node];
    }

    return 0;
}

void update(int node, int left, int right, int low, int high, int u) {
    if (left <= low and high <= right) {
        tree[node] += u;
    } else if (right < low or left > high) {
        return;
    } else if (low <= high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        update(child, left, right, low, mid, u);
        update(child + 1, left, right, mid + 1, high, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll arr[n];
    INPUT(n, arr);

    int a, b, t, u;
    while(m --){
        cin >> t;
        if(t == 2){
            cin >> a;
            a --;
            cout << arr[a] + queries(1, a, 0, n - 1) << newline;
        }
        else{
            cin >> a >> b >> u;
            a --, b--;
            update(1, a, b, 0, n - 1, u);
        }
    }

    return 0;
}
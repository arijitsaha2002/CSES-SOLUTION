#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, q;
const int MaxN = 2e5 + 3;
vector<int> Nodes[MaxN];
int Value[MaxN];
int NewValue[MaxN];
int Index[MaxN];
int ArrSize[MaxN];
int Counter = 0;

int dfs(int node, int parent) {
    Index[node] = Counter;
    Counter ++;

    int m = 1;

    for (int adj : Nodes[node]) {
        if (adj != parent) {
            m += dfs(adj, node);
        }
    }

    ArrSize[node] = m;
    return m;
}


const int MaxTree = 1e6;
long Tree[MaxTree];

void build(int node, int low, int high) {
    if (low == high) {
        Tree[node] = NewValue[low];
    }
    else if (low < high) {
        int child = node << 1;
        int mid = (low + high) >> 1;
        build(child, low, mid);
        build(child + 1, mid + 1, high);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

void update(int node, int low, int high, int index, int value) {
    if (low == high) {
        if (low == index) {
            Tree[node] = value;
        }
    }
    else if (low <= index and index <= high) {
        int child = node << 1;
        int mid = (low + high) >> 1;
        update(child, low, mid, index, value);
        update(child + 1, mid + 1, high, index, value);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

long queries(int node, int low, int high, int left, int right) {
    if (left <= low and high <= right) {
        return Tree[node];
    }
    else if (high < left or right < low) {
        return 0;
    }

    int child = node << 1;
    int mid = (low + high) >> 1;
    long ql = queries(child, low, mid, left, right);
    long qr = queries(child + 1, mid + 1, high, left, right);
    return ql + qr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    int a, b;

    for (int i = 1; i <= n; i++) {
        cin >> Value[i];
    }

    for (int  i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        NewValue[Index[i]] = Value[i];
    }

    build(1, 0, n - 1);

    int t;
    while (q --) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            update(1, 0, n - 1, Index[a], b);
        }
        else{
            cin >> a;
            cout << queries(1, 0, n - 1, Index[a], Index[a] + ArrSize[a] - 1) << newline;
        }
    }


    return 0;
}
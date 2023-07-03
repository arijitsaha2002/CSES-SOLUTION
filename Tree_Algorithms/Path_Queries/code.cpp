#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (long i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (long i = a; i < b; i++)
#define blankChar ' '
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<long, null_type, less<long>, rb_tree_tag, tree_order_statistics_node_update>

long n, q;
const long MaxN = 2e5 + 3;
vector<long> Nodes[MaxN];
long Value[MaxN];
long In[MaxN];
long Out[MaxN];
long Counter = 0;
long Arr[MaxN];

long dfs(long node, long parent) {
    In[node] = Counter;
    Arr[Counter] = Value[node];
    Counter ++;

    long m = 1;

    for (long adj : Nodes[node]) {
        if (adj != parent) {
            m += dfs(adj, node);
        }
    }

    Arr[Counter] = -Value[node];
    Out[node] = Counter;
    Counter ++;
    return m;
}


const long MaxTree = 1e6;
long Tree[MaxTree];

void build(long node, long low, long high) {
    if (low == high) {
        Tree[node] = Arr[low];
    }
    else if (low < high) {
        long child = node << 1;
        long mid = (low + high) >> 1;
        build(child, low, mid);
        build(child + 1, mid + 1, high);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

void update(long node, long low, long high, long index, long value) {
    if (low == high) {
        if (low == index) {
            Tree[node] = value;
        }
    }
    else if (low <= index and index <= high) {
        long child = node << 1;
        long mid = (low + high) >> 1;
        update(child, low, mid, index, value);
        update(child + 1, mid + 1, high, index, value);
        Tree[node] = Tree[child] + Tree[child + 1];
    }
}

long queries(long node, long low, long high, long left, long right) {
    if (left <= low and high <= right) {
        return Tree[node];
    }
    else if (high < left or right < low) {
        return 0;
    }

    long child = node << 1;
    long mid = (low + high) >> 1;
    long ql = queries(child, low, mid, left, right);
    long qr = queries(child + 1, mid + 1, high, left, right);
    return ql + qr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    long a, b;

    for (long i = 1; i <= n; i++) {
        cin >> Value[i];
    }

    for (long  i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    dfs(1, 0);
    build(1, 0, Counter - 1);

    long t;
    while (q --) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            update(1, 0, Counter - 1, In[a], b);
            update(1, 0, Counter - 1, Out[a], -b);
        }
        else{
            cin >> a;
            cout << queries(1, 0, Counter - 1, 0 , In[a]) << newline;
        }
    }


    return 0;
}
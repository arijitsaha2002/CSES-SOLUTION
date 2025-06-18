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
const long MaxN = 2e5 + 1;
vector<int> Nodes[MaxN];
int Value[MaxN];
int In[MaxN];
int MyOut[MaxN];
long Arr[MaxN << 1];
long long Counter = 0;

void dfs(long node, long parent) {
    In[node] = Counter;
    Arr[Counter] = Value[node];
    Counter ++;

    for (long adj : Nodes[node]) {
        if (adj != parent) {
            dfs(adj, node);
        }
    }

    Arr[Counter] = -Value[node];
    MyOut[node] = Counter;
    Counter ++;
}


const long MaxTree = 1e6;
long long Tree[MaxTree];

void build() {
    for (int i = 0; i < Counter; i ++) {
        Tree[Counter + i] = Arr[i];
    }

    for (int i = Counter - 1; i >= 1; i --) {
        Tree[i] = Tree[i << 1] + Tree[(i << 1) + 1];
    }
}

void update(long long index, long long value) {
    index += Counter;
    Tree[index] = value;

    while (index > 1) {
        index >>= 1;
        Tree[index] = Tree[index << 1] + Tree[(index << 1) + 1];
    }
}

long long queries(long left, long right) {
    left += Counter;
    right += Counter;
    long long sum = 0;

    while (left < right) {
        if (left & 1) {
            sum += Tree[left];
            left ++;
        }

        if (right & 1) {
            right --;
            sum += Tree[right];
        }

        left >>= 1;
        right >>= 1;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    long long a, b;

    for (long i = 1; i <= n; i++) {
        cin >> Value[i];
    }


    for (long  i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    dfs(1, 0);
    build();

    long t;
    while (q --) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            update(In[a], b);
            update(MyOut[a], -b);
        }
        else {
            cin >> a;
            long ans = queries(0 , In[a] + 1);
            cout << ans << endl;
        }
    }
    return 0;
}
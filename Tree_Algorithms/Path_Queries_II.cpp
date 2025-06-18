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
#define point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 2e5 + 1;
int Value[MaxN];
vector<int> Nodes[MaxN];
int counter = 0;
vector<vector<int>> Arr;
point level[MaxN];
int height[MaxN];
int VectorMapping[MaxN];
int IndexMapping[MaxN];
int startNode[MaxN];
int n, q, a, b;
int dp[MaxN][31];

void fill_level(int node, int parent) {
    level[node] = {0, 0};
    height[node] = height[parent] + 1;
    dp[node][0] = parent;
    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            fill_level(adj, node);
            if (level[adj].first + 1 > level[node].first) {
                level[node] = {level[adj].first + 1, adj};
            }
        }
    }
}

void fill_array(int node, int parent, vector<int> &v, int index) {
    IndexMapping[node] = v.size();
    v.push_back(node);
    VectorMapping[node] = index;


    for (int adj : Nodes[node]) {
        if (adj != parent and adj != level[node].second) {
            vector<int> p;
            Arr.push_back(p);
            int i = Arr.size() - 1;
            fill_array(adj, node, p, i);
            Arr[i] = p;
            startNode[i] = node;
        }
    }
    if (level[node].second) fill_array(level[node].second, node, v, index);
}

vector<vector<int>> Tree;

void build(int node, int low, int high, int i) {
    if (low == high) {
        Tree[i][node] = Value[Arr[i][low]];
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(child, low, mid, i);
        build(child + 1, mid + 1, high, i);
        Tree[i][node] = max(Tree[i][child], Tree[i][child + 1]);
    }
}

void update(int i, int node, int low, int high, int index, int value) {
    if (low == high) {
        if (low == index) {
            Tree[i][node] = value;
        }
    }
    else if (low <= index and index <= high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        update(i, child , low, mid, index, value);
        update(i, child + 1, mid + 1, high, index, value);
        Tree[i][node] = max(Tree[i][child], Tree[i][child + 1]);
    }
}

int queries(int i, int node, int low, int high, int left, int right) {
    if (left <= low and high <= right) {
        return Tree[i][node];
    }
    else if (right < low or high < left) {
        return 0;
    }
    else if (low < high) {
        int mid = (low + high) >> 1;
        int child = node << 1;
        int ql = queries(i, child, low, mid, left, right);
        int qr = queries(i, child + 1, mid + 1, high, left, right);
        return max(ql , qr);
    }
    return 0;
}

void fill_dp() {
    for (int j = 1; j < 31; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int get_parent(int a, int i) {
    int curr = 0;
    while (i) {
        if (i & 1) a = dp[a][curr];
        i >>= 1;
        curr ++;
    }
    return a;
}

int lca(int a, int b) {
    if (dp[a][0] == dp[b][0]) return dp[a][0];

    if (height[a] != height[b]) {
        if (height[a] > height[b]) swap(a, b);
        b = get_parent(b, height[b] - height[a]);
        if (a == b) return a;
    }

    if (dp[a][0] == dp[b][0]) return dp[a][0];

    for (int i = 1; i < 31; i++) {
        if (dp[a][i] == dp[b][i]) {
            return lca(dp[a][i - 1], dp[b][i - 1]);
        }
    }
    return 1;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> Value[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }


    fill_level(1, 0);

    vector<int> v = {};
    int i = 0;
    Arr.push_back(v);
    fill_array(1, 0, v, Arr.size() - 1);
    Arr[i] = v;

    Tree.resize(Arr.size());

    for (int i = 0; i < (int)Arr.size(); i ++) {
        Tree[i] = vector<int>(Arr[i].size() << 2);
        build(1, 0, Arr[i].size() - 1, i);
    }

    fill_dp();

    // for(int i = 1; i <= n; i++){
    //     cout << " ---- " << i << " ---- " << endl;
    //     for (int j = 0; j < 5; j++){
    //         cout << dp[i][j] << blankChar;
    //     }
    //     cout << endl;
    // }

    // exit(0);

    int a, b;
    while (q --) {
        cin >> a;
        if (a == 1) {
            cin >> a >> b;
            int i = VectorMapping[a];
            int index = IndexMapping[a];
            update(i, 1, 0, Arr[i].size() - 1, index, b);
        }
        else {
            cin >> a >> b;
            int l = lca(a, b);
            if (a == b) l = a;

            int ans = 0;
            while (VectorMapping[a] != VectorMapping[l]) {
                ans = max(ans, queries(VectorMapping[a], 1, 0, Arr[VectorMapping[a]].size() - 1, 0, IndexMapping[a]));
                a = startNode[VectorMapping[a]];
            }

            ans = max(ans, queries(VectorMapping[a], 1, 0, Arr[VectorMapping[a]].size() - 1, IndexMapping[l], IndexMapping[a]));

            while (VectorMapping[b] != VectorMapping[l]) {
                ans = max(ans, queries(VectorMapping[b], 1, 0, Arr[VectorMapping[b]].size() - 1, 0, IndexMapping[b]));
                b = startNode[VectorMapping[b]];
            }

            ans = max(ans, queries(VectorMapping[b], 1, 0, Arr[VectorMapping[b]].size() - 1, IndexMapping[l], IndexMapping[b]));

            cout << ans << blankChar;
        }
    }
    cout << endl;
    return 0;
}
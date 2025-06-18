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
const int MaxN = 1e5 + 2;
vector<int> Nodes[MaxN << 1];
set<int> parentNodes[MaxN << 1];
vector<int> RevNodes[MaxN << 1];
int Parent[MaxN << 1];
bool is_visited[MaxN << 1];
int sortedNodes[MaxN << 1];
int counter = 2 * n;

void add_parent(int node, int parent) {
    is_visited[node] = true;
    Parent[node] = parent;

    for (auto adj : RevNodes[node]) {
        if (not is_visited[adj]) {
            is_visited[adj] = true;
            add_parent(adj, parent);
        }
    }
}

void add_edge(int a, int b) {
    // cout << (a + n) % (n << 1) << " node " << b << newline;
    Nodes[((a + n - 1) % (n << 1)) + 1].push_back(b);
    RevNodes[b].push_back(((a + n - 1) % (n << 1)) + 1);
    // cout << (b + n) % (n << 1) << " node " << a << newline;
    Nodes[((b + n - 1) % (n << 1)) + 1].push_back(a);
    RevNodes[a].push_back(((b + n - 1) % (n << 1)) + 1);
}

void topology_sort(int node) {
    is_visited[node] = true;

    for (auto adj : parentNodes[node]) {
        if (not is_visited[adj]) {
            is_visited[adj] = true;
            topology_sort(adj);
        }
    }

    sortedNodes[node] = counter --;
}

vector<int> sort_node;
void dfs(int node) {
    is_visited[node] = true;

    for (auto adj : Nodes[node]) {
        if (not is_visited[adj]) {
            is_visited[adj] = true;
            dfs(adj);
        }
    }
    sort_node.push_back(node);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char t;
    int a, b;

    cin >> m >> n;
    for (int i = 0; i < m; i ++) {
        cin >> t >> a;
        if (t == '-') a += n;
        cin >> t >> b;
        if (t == '-') b += n;
        add_edge(a, b);
    }

    // cout << "come-1" << endl;

    for (int i = 1; i  <= 2 * n; i++) {
        if (not is_visited[i]) dfs(i);
    }

    reverse(sort_node.begin(), sort_node.end());
    fill(is_visited, is_visited + (MaxN << 1), 0);

    for (auto i : sort_node) {
        if (not is_visited[i]) add_parent(i, i);
    }

    // exit(0);

    // cout << "come0" << endl;

    for (int i = 1; i  <= 2 * n; i++) {
        for (auto adj : Nodes[i]) {
            parentNodes[Parent[i]].insert(Parent[adj]);
        }
    }

    fill(is_visited, is_visited + (MaxN << 1), 0);
    // cout << "come1" << endl;

    for (int i = 1; i  <= 2 * n; i++) {
        if (Parent[i] == i) {
            if (not is_visited[i]) topology_sort(i);
        }
    }

    // cout << "come2" << endl;
    string s;

    for (int i = 1; i <= n; i ++) {
        if (Parent[i] == Parent[i + n]) {
            cout << "IMPOSSIBLE" << newline;
            return 0;
        }
        if (sortedNodes[Parent[i]] < sortedNodes[Parent[i + n]]) {
            s.push_back('-');
            s.push_back(' ');
        }
        else {
            s.push_back('+');
            s.push_back(' ');
        }
    }

    s.pop_back();

    cout << s << endl;
    return 0;
}
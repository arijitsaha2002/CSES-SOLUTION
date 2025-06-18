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

const int MaxN = 2e5 + 1;
vector<int> Nodes[MaxN];
long BrachSize[MaxN];
long Answer[MaxN];
int n, a, b;

int set_size(int node, int parent, int level) {
    Answer[1] += level;

    int m = 1;
    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            m += set_size(adj, node, level + 1);
        }
    }

    BrachSize[node] = m;
    return m;
}

void fill_answer(int node, int parent) {
    Answer[node] = Answer[parent] + n;
    Answer[node] -= BrachSize[node] << 1;

    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            fill_answer(adj, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for (int i = 1; i < n; i ++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    set_size(1, 0, 0);

    for (auto adj : Nodes[1]) {
        fill_answer(adj, 1);
    }


    for (int i = 1; i <= n; i++) {
        cout << Answer[i] << blankChar;
    }

    cout << endl;

    return 0;
}
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

const int MaxN = 2e5 + 3;
vector<int> Nodes[MaxN];
int color[MaxN];
int answer[MaxN];
unordered_set<int> SET[MaxN];
unordered_set<int> *setptr[MaxN];
int counter = 0;

int bfs(int node, int parent) {
    int maxChild = -1;
    int mx = 0;

    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            auto ans = bfs(adj, node);
            if (ans > mx) {
                maxChild = adj;
                mx = ans;
            }
        }
    }

    if (maxChild == -1) {
        SET[counter].insert(color[node]);
        setptr[node] = &SET[counter];
        counter ++;
    }
    else {
        setptr[node] = setptr[maxChild];
        setptr[node]->insert(color[node]);

        for (auto adj : Nodes[node]) {
            if (adj != parent and adj != maxChild) {
                setptr[node]->insert(setptr[adj]->begin(), setptr[adj]->end());
            }
        }
    }

    answer[node] = setptr[node]->size();
    return setptr[node]->size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    bfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << blankChar;
    }

    cout << endl;

    return 0;
}
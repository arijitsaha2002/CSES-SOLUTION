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

int Parent[MaxN];

int Child1[MaxN];
int Value1[MaxN];

int Child2[MaxN];
int Value2[MaxN];

int set_one(int node, int parent) {
    int ans = 0;
    for (int adj : Nodes[node]) {
        if (adj != parent) {
            ans = set_one(adj, node) + 1;
            if (ans >= Value1[node]) {
                Value2[node] = Value1[node];
                Child2[node] = Child1[node];

                Value1[node] = ans;
                Child1[node] = adj;
            }
            else if (ans > Value2[node]) {
                Value2[node] = ans;
                Child2[node] = adj;
            }

        }
    }
    return Value1[node];
}

void bfs(int node, int parent) {
    if (Child1[parent] != node) {
        Parent[node] = max(Parent[node] , Value1[parent] + 1);
    }

    if (Child2[parent] != node) {
        Parent[node] = max(Parent[node] , Value2[parent] + 1);
    }

    Parent[node] = max(Parent[node] ,Parent[parent] + 1);


    for (auto adj : Nodes[node]) {
        if (adj != parent) {
            bfs(adj, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    Parent[1] = 0;
    set_one(1, 0);


    // for (auto adj : Nodes[1]) {
    //     int ans = set_one(adj, 1);
    //     if (ans >= Value1[1]) {
    //         Value2[1] = Value1[1];
    //         Child2[1] = Child1[1];

    //         Value1[1] = ans;
    //         Child1[1] = adj;
    //     }
    //     else if (ans > Value2[1]) {
    //         Value2[1] = ans;
    //         Child2[1] = adj;
    //     }
    // }

    for (auto adj : Nodes[1]) {
        bfs(adj, 1);
    }


    for(int i = 1; i <= n; i ++){
        cout << max(max(Parent[i], Value1[i]), Value2[i]) << blankChar;
    }
    cout << endl;

    return 0;
}
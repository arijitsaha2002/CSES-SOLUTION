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

const int MaxN = 2e5 + 5;
int n, q;
vector<int> Nodes[MaxN], Parent[MaxN];


void set_parent(int node, int parent) {

    Parent[node].push_back(parent);

    int curr = 1;
    while (true) {
        if (Parent[parent].size() < curr) break;
        parent = Parent[parent][curr - 1];
        Parent[node].push_back(parent);
        curr += 1;
    }

    for (auto child : Nodes[node]) {
        set_parent(child, node);
    }
}

int get_parent(int node, int level){
    int m = 0;

    int curr = 1, parent = node;
    while (level) {
        if(level % 2 == 1){
            if(Parent[parent].size() < curr){
                return -1;
            }
            parent = Parent[parent][curr - 1];
        }
        curr += 1;
        level >>= 1;
    }

    return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    int a, b;

    for (int i = 2; i <= n; i++) {
        cin >> a;
        Nodes[a].push_back(i);
    }


    for (auto child : Nodes[1]) {
        set_parent(child, 1);
    }


    // for(int i = 1; i <= n; i++){
    //     cout << i << "  ----  " << blankChar;
    //     for(auto j : Parent[i]){
    //         cout << j << blankChar;
    //     }
    //     cout << endl;
    // }

    while (q --) {
        cin >> a >> b;
        cout << get_parent(a, b) << newline;
    }

    return 0;
}
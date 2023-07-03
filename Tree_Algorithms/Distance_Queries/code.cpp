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
int Level[MaxN];


void set_parent(int node, int parent, int l) {

    int p = parent;
    Parent[node].push_back(parent);
    Level[node] = l;

    int curr = 1;
    while (true) {
        if (Parent[parent].size() < curr) break;
        parent = Parent[parent][curr - 1];
        Parent[node].push_back(parent);
        curr += 1;
    }

    for (auto child : Nodes[node]) {
        if(child != p) set_parent(child, node, l + 1);
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

int get_cmn_parent(int a, int b){
    if(Parent[a][0] == Parent[b][0]){
        return Parent[a][0];
    }

    for(int i = Parent[a].size() - 1; i >= 0; i--){
        if(Parent[a][i] != Parent[b][i]){
            return get_cmn_parent(Parent[a][i], Parent[b][i]);
        }
    }

    return Parent[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    int a, b;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }


    Level[1] = 0;
    for (auto child : Nodes[1]) {
        set_parent(child, 1, 1);
    }


    while (q --) {
        cin >> a >> b;

        int ans = Level[a] + Level[b];

        if(Level[a] < Level[b]){
            b = get_parent(b, Level[b] - Level[a]);
        }
        else if(Level[a] > Level[b]){
            a = get_parent(a, Level[a] - Level[b]);
        }
        

        if(a == b){
            cout << ans -  (Level[a] << 1) << newline;
        }
        else{
            cout << ans -  (Level[get_cmn_parent(a, b)] << 1) << newline;
        }

    }

    return 0;
}
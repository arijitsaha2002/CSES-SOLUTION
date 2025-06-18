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

const int MaxN = 2e5 + 2;
vector<int> Nodes[MaxN];
vector<int> Parents[MaxN];
int Level[MaxN];
int Answer[MaxN];

void fill_parent(int node, int parent, int level) {
    int p = parent;
    Level[node] = level;
    Parents[node].push_back(parent);
    int curr = 0;

    while (curr < Parents[parent].size() ) {
        parent = Parents[parent][curr];
        Parents[node].push_back(parent);
        curr ++;
    }

    for (auto adj : Nodes[node]) {
        if (adj != p) {
            fill_parent(adj, node, level + 1);
        }
    }
}

int get_parent(int node, int k) {
    int curr = node;
    int c = 1;

    while (k) {
        if (k & 1) curr = Parents[curr][c - 1];
        c ++;
        k >>= 1;
    }

    return curr;
}

int get_lca(int x, int y){
    
    if(Parents[x][0] == Parents[y][0]) return Parents[x][0];

    for(int i = Parents[x].size() - 1; i > -1 ; i --){
        if(Parents[x][i] != Parents[y][i]){
            return get_lca(Parents[x][i], Parents[y][i]);
        }
    }

    return 1;
}

int lca(int x, int y){
    if(Level[x] < Level[y]){
        y = get_parent(y, Level[y] - Level[x]);
    }
    else if(Level[x] > Level[y]){
        x = get_parent(x, Level[x] - Level[y]);
    }

    if(x == y) return x;
    return get_lca(x, y);
}


void bfs(int node, int parent){
    for(int adj : Nodes[node]){
        if(adj != parent){
            bfs(adj, node);
            Answer[node] += Answer[adj];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, a, b;
    cin >> n >> p;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }


    for (auto adj : Nodes[1]) {
        fill_parent(adj, 1, 1);
    }

    for(int i = 0 ; i < p; i++){
        cin >> a >> b;
        Answer[a]++;
        Answer[b]++;
        int l = lca(a, b);
        Answer[l] --;
        if(l != 1) Answer[Parents[l][0]] --;
    }

    bfs(1, 0);


    for(int i = 1; i <= n; i++){
        cout << Answer[i] << blankChar;
    }
    cout << endl;

    return 0;
}
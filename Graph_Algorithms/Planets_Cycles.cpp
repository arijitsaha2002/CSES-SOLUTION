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
int Nodes[MaxN];
int Answer[MaxN];
bool is_visited[MaxN];
int prev_level[MaxN];


void dfs(int node, int l){
    
    if(is_visited[node]){
        if(Answer[node]) return;
        else{
            Answer[node] = l - prev_level[node];
            dfs(Nodes[node], l + 1);
            return;
        }
    }
    
    is_visited[node] = true;
    prev_level[node] = l;
    
    dfs(Nodes[node], l + 1);

    if(Answer[node] == 0){
        Answer[node] = Answer[Nodes[node]] + 1;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> Nodes[i];

    for(int i = 1; i <= n; i++){
        if(not is_visited[i]){
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << Answer[i] << " ";
    }
    cout << endl;

    return 0;
}
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

const int MaxN = 2e5 + 4;
vector<int> Nodes[MaxN];
int Level[MaxN];

int set_level(int node, int parent, int level){
    
    Level[node] = level;
    int m = 0;

    for(auto child : Nodes[node]){
        if(child != parent){
            m = max(set_level(child, node, level + 1) + 1, m);
        }
    }

    return m;
}

void set_value(int node, int parent, int value){
    Level[node] += value;

    for(auto adj : Nodes[node]){
        if(adj != parent){
            set_value(adj, node, value);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }



    int maxChild1 = 0, maxChild2 = 0;
    int maxChildValue1 = 0, maxChildValue2 = 0;

    for(auto adj : Nodes[1]){
        int ans = set_level(adj, 1, 1);
        if(ans >= maxChildValue1){
            maxChild2 = maxChild1;
            maxChildValue2 = maxChildValue1;
            maxChild1 = adj;
            maxChildValue1 = ans;
        }
        else if (ans > maxChildValue2){
            maxChild2 = adj;
            maxChildValue2 = ans;
        }
    }

    for(auto adj : Nodes[1]){
        if(adj != maxChild1){
            set_value(adj, 1, maxChildValue1);
        }
    }

    

    return 0;
}
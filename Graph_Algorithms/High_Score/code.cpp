#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update>

const int MaxN = 2501;
vector<ll> Edges[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, edges, a, b;
    cin >> n >> edges;

    FOR(i, 0, edges){
        cin >> a >> b;
        Edges[a].push_back(b);
        Edges[b].push_back(a);
    }


    for(int i  = 1; i < n; i++){
        queue<int> Q;
        Q.push(1);
        while(! Q.empty()){
            
        }
    }

    return 0;
}
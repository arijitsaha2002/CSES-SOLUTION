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
vector<vector<int>> Nodes(MaxN, vector<int>());
bool is_visited[MaxN];
bool is_visited_[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    int endPoint, curr;
    queue<int> Q;

    Q.push(1);

    while(not Q.empty()){
        curr = Q.front();
        is_visited[curr] = true;
        Q.pop();

        for(auto adj : Nodes[curr]){
            if(not is_visited[adj]){
                Q.push(adj);
            }
        }
    }

    endPoint = curr;

    queue<Point> Path;
    Path.push({endPoint, 0});
    Point p;

    while(not Path.empty()){
        p = Path.front();
        is_visited_[p.first] = true;
        Path.pop();

        for(auto adj : Nodes[p.first]){
            if(not is_visited_[adj]){
                Path.push({adj, p.second + 1});
            }
        }
    }

    cout << p.second << endl;


    return 0;
}
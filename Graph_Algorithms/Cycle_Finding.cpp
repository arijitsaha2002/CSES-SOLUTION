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
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
const int MaxN = 2502;
vector<vector<Point>> Nodes(MaxN, vector<Point>());

long Dist[MaxN];
long Parent[MaxN];

bool isIn[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Nodes[a].push_back({b, c});
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto adj : Nodes[j]) {
                if (Dist[adj.first] > Dist[j] + adj.second) {
                    Parent[adj.first] = j;
                    Dist[adj.first] = Dist[j] + adj.second;
                }
            }
        }
    }


    for (int j = 1; j <= n; j++) {
        for (auto adj : Nodes[j]) {
            if (Dist[adj.first] > Dist[j] + adj.second) {
                
                Parent[adj.first] = j;
                cout << "YES" << newline;

                isIn[adj.first] = true;
                int curr = j;

                stack<int> Path;
                Path.push(adj.first);

                while(not isIn[curr]){
                    isIn[curr] = true;
                    Path.push(curr);
                    curr = Parent[curr];
                }

                cout << curr << blankChar;

                while (Path.top() != curr) {
                    cout << Path.top() << blankChar;
                    Path.pop();
                }
                cout << curr << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;

    return 0;
}
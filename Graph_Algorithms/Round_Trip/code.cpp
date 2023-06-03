#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e5 + 1;
vector<vector<int>> Nodes(MaxN, vector<int>());
bool is_visited[MaxN];
stack<int> Path;

void dfs(int n, int p) {
    is_visited[n] = true;
    Path.push(n);

    for (auto adj : Nodes[n]) {
        if (is_visited[adj]) {
            if (adj != p) {
                stack<int> Print;
                Print.push(adj);

                do {
                    Print.push(Path.top());
                    Path.pop();
                } while (Print.top() != adj);

                if (Print.size() > 3) {
                    cout << Print.size() << newline;
                    while(! Print.empty()){
                        cout << Print.top() << blankchar;
                        Print.pop();
                    }
                    exit(0);
                }
            }

        } else {
            dfs(adj, n);
        }
    }

    Path.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;

    FOR(i, 0, m) {
        cin >> a >> b;
        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    for (int i = 1; i < n; i++) {
        if (!is_visited[i]) {
            dfs(i, 0);
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
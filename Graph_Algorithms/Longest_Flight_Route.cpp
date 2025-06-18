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

const int MaxN = 1e5 + 4;
vector<vector<int>> Nodes(MaxN, vector<int>());
int child[MaxN];
int final;
int dpArr[MaxN];

int dp(int n) {

    if (n == final) {
        return 0;
    }

    if(dpArr[n] != 0){
        return dpArr[n];
    }

    int m = -6;

    for (auto adj : Nodes[n]) {
        int ans = dp(adj);
        if (ans >= 0) {
            if (ans > m) {
                child[n] = adj;
                m = ans;
            }
        }
    }

    dpArr[n] = m + 1;
    return m + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    final = n;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Nodes[a].push_back(b);
    }

    int ans = dp(1);
    if(ans >= 0){
        cout << ans + 1 << newline;
        int curr = 1;
        while(curr != final){
            cout << curr << blankChar;
            curr = child[curr];
        }
        cout << final << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
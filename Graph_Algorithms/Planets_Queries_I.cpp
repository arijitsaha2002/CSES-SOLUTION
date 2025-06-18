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
int Next[MaxN];
int dp[MaxN][31];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> dp[i][0];
    }


    for(int i = 1; i < 31; i ++){
        for(int node = 1; node <= n; node ++){
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
    }

    int a, b;
    while(m --){
        cin >> a >> b;

        int node = a, c = 0;
        while(b){
            if(b & 1){
                node = dp[node][c];
            }
            c ++;
            b >>= 1;
        }
        cout << node << newline;
    }

    return 0;
}
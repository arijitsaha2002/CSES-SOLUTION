#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Project {
   public:
    long start, end, reward;
};

bool cmp(const Project &p1, const Project &p2) { return (p1.end < p2.end) || (p1.end == p2.end && p1.start < p2.start); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;

    Project P[n];

    FOR(i, n) { cin >> P[i].start >> P[i].end >> P[i].reward; }

    sort(P, P + n, cmp);

    long dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        Project temp = P[i - 1];
        temp.end = temp.start - 1;
        auto it = upper_bound(P, P + n, temp, cmp);
        dp[i] = max(P[i - 1].reward + dp[it - P], dp[i - 1]);
    }

    cout << dp[n] << endl;

    return 0;
}
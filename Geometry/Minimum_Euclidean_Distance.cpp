#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 2e5 + 2;
point P[MaxN];

int get_dist(point p1, point p2) {

    int x = (p1.first - p2.first);
    x = x * x;
    int y = (p1.second - p2.second);
    y = y * y;

    return x + y;
}

int MinDist(int i, int j) {
    if (i == j - 1) return get_dist(P[i], P[j]);
    if (i == j) return 4e18;

    int mid = (i + j) / 2;
    int dl = MinDist(i, mid), dr = MinDist(mid + 1, j);
    int d = min(dl, dr);


    int x = upper_bound(P + i, P + j + 1, make_pair(P[mid].first - (int)sqrt(d) - 1, 0L)) - P;
    int y = upper_bound(P + i, P + j + 1, make_pair(P[mid].first + (int)sqrt(d) + 1, 0L)) - P - 1;

    vector<point> V;
    for (int k = x; k <= y; k++) {
        V.push_back({P[k].second, P[k].first});
    }
    sort(V.begin(), V.end());

    for (int k = 0; k < V.size(); k++) {
        for (int l = k + 1; l < V.size() and (V[l].first - V[k].first) * (V[l].first - V[k].first) < d; l++) {
            d = min(d, get_dist(V[k], V[l]));
        }
    }

    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        cin >> P[i].first >> P[i].second;
    }

    sort(P, P + n);
    cout << MinDist(0, n - 1) << endl;
    return 0;
}
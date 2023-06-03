#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define M INFINITY
#define newline ' '
#define FOR(i, N) for (int(i) = 0; (i) < N; (i)++)
#define blankchar ' '
#define Point pair<ll, ll>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

bool sort_x(Point p1, Point p2) { return p1.first < p2.first; }
bool sort_y(Point p1, Point p2) { return p1.second < p2.second; }

ll dist(Point p1, Point p2) {
    ll dx = (p1.first - p2.first);
    ll dy = (p1.second - p2.second);
    return dx * dx + dy * dy;
}

struct CustomCmp {
    bool operator()(const Point p1, const Point p2) { return p1.first < p2.first; }
};

ll solve(Point *P, int i, int j) {
    if (j <= i) return (ll)M;
    else if (j - i == 1) {
        return dist(P[i], P[j]);
    }

    int mid_index = (i + j) / 2;
    ll left_sol = solve(P, i, mid_index);
    ll right_sol = solve(P, mid_index + 1, j);

    // cout << right_sol << blankchar << left_sol << endl;

    ll sol = min(left_sol, right_sol);

    // cout << sol << endl;

    Point T = {P[mid_index].first - sol, 0};
    int new_i = upper_bound(P + i, P + j + 1, T, sort_x) - P;
    T = {P[mid_index].first + sol, 0};
    int new_j = lower_bound(P + i, P + j + 1, T, sort_x) - P;


    if (new_i <= mid_index and mid_index < new_j) {

        vector<Point> A(P + new_i, P + mid_index + 1);
        sort(A.begin(), A.end(), sort_y);

        vector<Point> B(P + mid_index + 1, P + new_j + 1);
        sort(B.begin(), B.end(), sort_y);

        for (int k = 0; k < A.size(); k++) {
            for (int l = 0; l < B.size(); l++) {
                sol = min(sol, dist(A[k], B[l]));
            }
        }
    }

    return sol;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    Point P[n];

    for (int i = 0; i < n; i++) {
        cin >> P[i].first >> P[i].second;
    }

    sort(P, P + n, sort_x);
    cout << solve(P, 0, n - 1) << endl;

    return 0;
}
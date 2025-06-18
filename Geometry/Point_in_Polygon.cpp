#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// INSIDE
// OUTSIDE
// BOUNDARY

#define Point pair<long, long>

void Solve(long x, long y, vector<Point> &P, size_t n) {
    size_t c = 0;
    long cp;
    for (size_t i = 0 ; i < n; i++) {

        Point P1 = P[i], P2 = P[i + 1];
        if (P2.second > P1.second) swap(P1, P2);

        if (P2.second <= y and x <= max(P1.first, P2.first)) {

            if (y <= P1.second and min(P1.first, P2.first) <= x) {
                cp = (x - P2.first) * (P1.second - P2.second) - (y - P2.second) * (P1.first - P2.first);
                if (cp == 0) {
                    cout << "BOUNDARY\n";
                    return;
                }
            }


            if ( y < P1.second) {
                if (x < min(P1.first, P2.first)) c++;
                else c += (cp < 0);
            }
        }
    }
    if (c % 2 == 1) cout << "INSIDE\n";
    else cout << "OUTSIDE\n";
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n, m;
    cin >> n >> m;
    vector<Point> P(n + 1);
    for_each(P.begin(), P.end() - 1, [](Point & p) {cin >> p.first >> p.second;});
    P[n] = P[0];
    long x, y;
    while (m--) {
        cin >> x >> y;
        Solve(x, y, P, n);
    }
    return 0;
}

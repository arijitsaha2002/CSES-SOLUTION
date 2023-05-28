#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define Point pair<long, long>

long long Area(vector<Point> &P, size_t n) {
    long long result = 0;
    for (size_t i = 0; i < n ; i++) {
        result += P[i].first * P[i + 1].second - P[i + 1].first * P[i].second;
    }
    return llabs(result);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    size_t n;
    cin >> n;

    vector<Point> P(n + 1);

    for_each(P.begin(), P.end() - 1, [](Point & p) {cin >> p.first >> p.second;});

    P[n] = P[0];

    long long A = Area(P, n);

    long long b = 0;

    for (size_t i = 0; i < n; i++) {
        b += __gcd(abs(P[i].first - P[i + 1].first), abs(P[i].second - P[i + 1].second));
    }

    cout <<  (A - b) / 2 + 1 << " " << b << endl;

    return 0;
}

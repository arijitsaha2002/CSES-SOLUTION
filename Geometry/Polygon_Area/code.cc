#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    size_t n;
    cin >> n;
    vector<pair<long, long>> P(n+1);
    for_each(P.begin(), P.end() - 1, [](pair<long, long> &p) {cin >> p.first >> p.second;});
    P[n] = P[0];
    long long result = 0;
    for (size_t i = 0; i < n ; i++) {
        result += P[i].first * P[i+1].second - P[i+1].first * P[i].second;
    }
    cout << llabs(result) << endl;

    return 0;
}

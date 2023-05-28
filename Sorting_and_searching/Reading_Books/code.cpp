#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<ll> P(n);
    for_each(P.begin(), P.end(), [](ll & p) { cin >> p;});
    ll maxValue = *max_element(P.begin(), P.end());
    ll sum = accumulate(P.begin(), P.end(), 0LL);
    cout << max(sum, (maxValue << 1)) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long long  n;
    cin >> n;
    vector<long long > Lengths(n);
    for_each(Lengths.begin(), Lengths.end(), [](long long  & a) {cin >> a;});
    sort(Lengths.begin(), Lengths.end());
    long long  medianOfLenghts = Lengths[(n >> 1)];
    for_each(Lengths.begin(), Lengths.end(), [&](long long  & a) { a = llabs(a - medianOfLenghts);});
    cout << accumulate(Lengths.begin(), Lengths.end(), 0LL) << "\n";
 
    return 0;
}

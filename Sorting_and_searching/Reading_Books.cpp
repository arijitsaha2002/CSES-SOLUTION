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
 
    ll sum = 0, maxValue = -1, temp;
    while (n--) {
        cin >> temp;
        sum += temp;
        maxValue = max(temp, maxValue);
    }
    cout << max(sum, (maxValue << 1)) << endl;
    return 0;
}

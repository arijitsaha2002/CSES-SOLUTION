#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long n;
    cin >> n;
    long long temp;
    cin >> temp;
    vector<long long>B;
    B.push_back(temp);
 
    for (long i = 1; i < n; i ++) {
 
        cin >> temp;
        auto l = upper_bound(B.begin(), B.end(), temp);
        if (l == B.end()) B.push_back(temp);
        else B[l - B.begin()] = temp;
 
    }
 
    cout << B.size() << endl;
 
    return 0;
}

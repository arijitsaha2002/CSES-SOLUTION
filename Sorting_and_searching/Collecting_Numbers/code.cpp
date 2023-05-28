#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>A(n);
    for_each(A.begin(), A.end(), [](int & n) {cin >> n;});

    vector<int>B(1);
    B[0] = -A[0];

    for (long i = 1; i < n; i ++) {

        auto l = upper_bound(B.begin(), B.end(), -A[i]);
        if (l == B.end()) B.push_back(-A[i]);
        else *l = -A[i];

    }

    cout << B.size() << endl;

    return 0;
}

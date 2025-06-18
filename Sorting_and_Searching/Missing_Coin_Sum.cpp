#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    long n;
    cin >> n;
    vector<long long> A(n);
    for_each(A.begin(), A.end(), [](long long & s) {cin >> s;});
    sort(A.begin(), A.end());

    long long r = 1;
    for (n = 0; n < A.size() and A[n] <= r ; n ++) {
        r += A[n];
    }

    cout << r << endl;

    return 0;
}

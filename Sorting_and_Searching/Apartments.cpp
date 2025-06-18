#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int s = 0, j = 0, i = 0;
    while (i < n and j < m) {
        if (abs(A[i] - B[j]) <= k) {
            s++;
            j++;
            i++;
        } else if (B[j] < A[i]) {
            j++;
        } else if (B[j] > A[i]) {
            i++;
        }
    }
    cout << s << endl;
    return 0;
}
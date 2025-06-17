#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
 
#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> A(n, 0), B(n, 0);
 
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }
 
    sort(A.begin(), A.end());
 
    ll sum = 0, r = 0;
 
    for (int i = 0; i < n; i++) {
        sum += A[i];
        r += (B[i] - sum);
    }
 
    cout << r << endl;
 
    return 0;
}

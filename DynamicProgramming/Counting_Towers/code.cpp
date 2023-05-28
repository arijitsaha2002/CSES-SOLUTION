#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long

#define N 1000000
#define M 1000000007

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int n;

    vector<long> T(N + 1);

    T[0] = 1;
    T[1] = 2;


    long T_n = 2, S_n = 1;

    for (long i = 2; i <= N; i++) {
        T[i] = ((5 * T_n  - (S_n<<1)) % M + M) % M;
        S_n = (S_n + T_n) % M;
        T_n = T[i];
    }

    while (t--) {
        cin >> n;
        cout << T[n] << "\n";
    }

    return 0;
}
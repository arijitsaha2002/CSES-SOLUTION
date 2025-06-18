#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;

#define ll long long
#define M 1000000007
#define N 1000001

bitset<32> bin_M(M - 2);

ll Factorial[N];
ll iFactorial[N];


long inverse_M(long n) {

    long result = 1, m = n;

    for (int i = 0; i < 32; i++) {
        if (bin_M.test(i)) result = (result * m) % M;
        m = (m * m) % M;
    }

    return result;
}


void fill_factorial() {
    Factorial[0] = 1;
    for (int i = 1; i < N; i++ ) {
        Factorial[i] = (i * Factorial[i - 1]) % M;
    }

    iFactorial[N - 1] = inverse_M(Factorial[N - 1]);

    for (int i = N - 2; i >= 0; i-- ) {
        iFactorial[i] = (iFactorial[i + 1] * (i + 1));
        iFactorial[i] %= M;
    }

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    fill_factorial();

    long t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (iFactorial[a - b] * (Factorial[a] * iFactorial[b] % M)) % M << "\n";
    }

    return 0;
}
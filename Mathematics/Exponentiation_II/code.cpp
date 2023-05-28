#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

#define ll long long
// ll M = 1000000007;

long power(long &a, long &b, long M) {
    long result = 1, m = a;
    while (b) {
        if (b & 1) result *= m;
        result %= M;
        m = (m * m) % M;
        b >>= 1;
    }
    return result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, a, b, c;
    cin >> n;

    while (n--) {
        cin >> a >> b >> c;
        c = power(b, c, 1000000006);
        cout << power(a, c, 1000000007) << "\n";
    }

    return 0;
}
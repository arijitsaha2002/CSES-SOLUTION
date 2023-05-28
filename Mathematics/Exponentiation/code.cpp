#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

#define ll long long
#define M 1000000007

long power(long &a, long &b) {
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

    long n, a, b;
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }

    return 0;
}
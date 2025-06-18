#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'


long power(long a, long b) {
    long r = 1, m = a;
    while (b) {
        if (b & 1) r = (r * m) % M;
        b >>= 1;
        m = (m * m) % M;
    }
    return r;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    if (n & 1) {
        cout << 0 << newline;
        return 0;
    }

    m = (n >> 1);

    long ne = 1, de = 1, i = m + 1, j = m + 1;

    while (j > 1) {
        de = (de * j) % M;
        ne = (ne * i) % M;
        i ++;
        j --;
    }

    cout << (ne * power(de, M-2)) % M<< newline;

    return 0;
}
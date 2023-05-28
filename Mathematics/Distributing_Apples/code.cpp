#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

#define ll long long
#define M 1000000007

int gcdExtended(int a, int b, int* x, int* y)
{

    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int A)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);

    int res = (x % M + M) % M;
    return res;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, result = 1, i;

    cin >> n >> m;

    for (i = 1; i <= n - 1; i++) {
        result = (result * (m + i)) % M;
    }

    ll ne = result;

    result = 1;

    for (i = 1; i <= n - 1; i++) {
        result = (result * i) % M;
    }

    ll de = result;

    cout << (ne * modInverse(de)) % M << endl;

    return 0;
}
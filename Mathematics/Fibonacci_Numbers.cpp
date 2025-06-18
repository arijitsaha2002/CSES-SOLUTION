#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007

class Matrix {
public:
    ll a1, a2, b1, b2;
};

Matrix Multiply(Matrix &a, Matrix &b) {

    Matrix temp;

    temp.a1 = (a.a1 * b.a1 + a.a2 * b.b1) % M;
    temp.a2 = (a.a1 * b.a2 + a.a2 * b.b2) % M;
    temp.b1 = (a.b1 * b.a1 + a.b2 * b.b1) % M;
    temp.b2 = (a.b1 * b.a2 + a.b2 * b.b2) % M;

    return temp;
}

ll getFibb(ll n) {
    Matrix r;
    r.a1 = 1, r.a2 = 0, r.b1 = 0, r.b2 = 1;
    Matrix m;
    m.a1 = 1, m.a2 = 1, m.b1 = 1, m.b2 = 0;

    while (n) {
        if (n & 1) r = Multiply(r, m);
        n >>= 1;
        m = Multiply(m, m);
    }

    return r.a1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    if (n) cout << getFibb(n - 1) << endl;
    else cout << 0 << endl;


    return 0;
}
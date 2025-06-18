#include <iostream>
using namespace std;


long setBitNumber(long n) {
    return 1 << (63 - __builtin_clz(n));
}


long getValue(long n, long i) {

    if (i == n) return 1;

    long pivot = 1;
    long m = 2;
    long l = n >> 1;
    long init_value = 2;

    while (pivot + l <= i) {
        pivot += l;
        l >>= 1;
        init_value += (m >> 1);
        m <<= 1;
    }

    return init_value + (i - pivot) * (m);
}


long foo(long n, long k) {

    long m = (1 << (63 - __builtin_clz(n)));

    long l = n - m;
    long ans = getValue(m, k - l);


    if (l == 0) {
        return ans;
    }

    l = (l << 1) + ans;

    if ( l <= n) {
        return l;
    }

    return ((l << 1) - 1 + n) % n;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    long n, i;


    while (q--) {
        cin >> n >> i;
        cout << foo(n, i) << "\n";
    }


    return 0;
}
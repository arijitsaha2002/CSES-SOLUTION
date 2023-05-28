#include <iostream>
using namespace std;


long setBitNumber(long n) {
    long k = __builtin_clz(n);
    return 1 << (63 - k);
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

    long m = setBitNumber(n);

    long l = n - m;


    long s = 2 * l + 1;

    long ans = getValue(m, k - l);


    if (l == 0) {
        return ans;
    }

    if (2 * l + ans <= n) {
        return 2 * l + ans;
    }
    else {
        return (n + 1 + (2 * l + ans - n - 1) * 2) % n;
    }
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
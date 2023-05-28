#include <iostream>
#include <bitset>
using namespace std;

#define ll long long
const ll M = 1000000007;




ll sum_b(ll a, ll b) {

    if (b == a) return 0;

    if ( (b - a) & 1 ) {
        return (((b - a) % M) * (((b + a + 1) >> 1) % M)) % M;
    }
    return ((((b - a) >> 1) % M) * ((b + a + 1) % M)) % M;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll q, result = 0;
    cin >> q;

    for (ll i = 1; i * i <= q; i++) {

        result += ((q / i) * i);
        result %= M;

        result += (i * (sum_b(max(q / (i + 1), i), q / i) % M) ) % M;
        result %= M;
    }

    cout << result << endl;
    return 0;
}
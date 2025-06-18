#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007

ll Power(ll a, ll b) {
    b %= (M - 1);
    ll r = 1, m = a;
    while (b) {
        if (b & 1) r = (r * m) % M;
        m = (m * m) % M;
        b >>= 1;
    }
    return r;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long count = 1, count1 = 1, first, second, sums = 1, number = 1, sqrt_number = 1;
    bool is_perfect_sqr = true;

    for (int i = 0; i < n; i++) {
        cin >> first >> second;



        if (is_perfect_sqr and (second & 1)) {
            count1 *= ((second + 1) >> 1) % (M - 1);
            count1 %= M - 1;
        }
        else{
            count1 *= (second + 1) % (M - 1);
            count1 %= M - 1;            
        }

        if (second & 1) is_perfect_sqr = false;

        count *= (second + 1) % M;
        count %= M;



        sums *= ((Power(first, second + 1) - 1) * Power(first - 1, M - 2)) % M;
        sums %= M;


        number *= Power(first, second);
        number %= M;

        sqrt_number *= Power(first, (second >> 1));
        sqrt_number %= M;

    }

    cout << count << " " << sums << " ";

    if (is_perfect_sqr) {
        cout << Power(sqrt_number, count1) << "\n";
    }
    else {
        cout << Power(number, count1) << "\n";
    }

    return 0;
}
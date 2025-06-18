#include <iostream>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long n, x;
    cin >> n;
    long sum = n * (n + 1) / 2;
    for(int i = 0; i < n - 1; i++) {
        cin >> x;
        sum -= x;
    }
    cout << sum << '\n';
    return 0;
}

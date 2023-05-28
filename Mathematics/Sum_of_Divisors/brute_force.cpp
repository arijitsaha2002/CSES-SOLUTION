#include <iostream>
using namespace std;


int main() {
    long q, result = 0;
    cin >> q;
    for (long i = 1; i <= q; i++) {
        result += i * (q / i);
    }
    cout << result << endl;
    return 0;
}

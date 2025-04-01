#include <iostream>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long n;
    cin >> n;
    cout << n << " ";
    while(n != 1) {
        if (n & 1) {
            n = 3 * n + 1;
        }
        else {
            n = n >> 1;
        }
        cout << n << " ";
    } 
    cout << endl;
    return 0;
}

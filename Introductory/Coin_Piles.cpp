#include <iostream>
using namespace std;


int main() {
    int t, a, b;
    cin >> t;
    while(t --) {
        cin >> a >> b;
        if ((a + b) % 3 == 0 and max(a, b) <= 2*min(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

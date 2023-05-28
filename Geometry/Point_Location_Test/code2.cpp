#include <iostream>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long testCase;
    cin >> testCase;
    long long x1, x2, x3, y1, y2, y3, cp;
    while (testCase--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;
        cp = x2*y3 - x3*y2;
        if(cp == 0) cout << "TOUCH\n";
        else if(cp > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";

    }
    return 0;
}

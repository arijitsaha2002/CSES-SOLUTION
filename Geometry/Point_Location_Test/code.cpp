#include <iostream>
#include <cmath>
using namespace std;

bool xnor(bool a, bool b) {
    return (a && b) || ( (!a) && (!b));
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long testCase;
    cin >> testCase;
    long long x1, x2, x3, y1, y2, y3, m1, m2, c;
    while (testCase--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        m1 = (x2 - x1);
        m2 = (y1 - y2);
        c = -m2 * x1 - m1 * y1;
        if (m1 * y3 + m2 * x3 + c == 0) {
            cout << "TOUCH" << endl;
        }
        else if (m1 == 0) {
            bool isLeft = xnor(y1 < y2, x3 < x1);
            cout << (isLeft ? "LEFT"  : "RIGHT") << endl;
        }
        else {
            bool isLeft = xnor(x1 > x2, (double)( -m2 * x3 - c) / (double) m1 > (double)y3);
            cout << (isLeft ? "LEFT"  : "RIGHT") << endl;
        }

    }
    return 0;
}

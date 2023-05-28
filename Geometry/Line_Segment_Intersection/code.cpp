#include <iostream>
#include <cmath>
using namespace std;

#define ERROR .0001

class Point {
public:
    double x, y;
    void takePoint() {
        cin >> x >> y;
    }
    double Distance(Point P) {
        return  sqrt(pow(x - P.x, 2) + pow(y - P.y, 2));
    }
};

class Line {
public:
    double m, c, x;
    bool isMundefine;

    Line(Point P1, Point P2) {
        isMundefine = false;
        if (abs(P2.x - P1.x) < ERROR) {
            x = P1.x;
            isMundefine = true;
        }
        else {
            m  = (P2.y - P1.y) / (P2.x - P1.x);
            // cout << P1.x << P1.y << P2.x << P2.y << endl;
            c = P1.y - P1.x * m;
        }
    }

    bool isSame(Line &L) {
        if (L.isMundefine) {
            return isMundefine && (abs(x - L.x) < ERROR);
        }
        else if (isMundefine) {
            return false;
        }
        else {
            return abs(m - L.m) < ERROR and abs(c - L.c) < ERROR;
        }
    }

    bool isSameSlope(Line &L) {
        cout << m << "  ----  " << L.m << endl;
        if (L.isMundefine) return L.isMundefine;
        else return abs(m - L.m) < ERROR;
    }

    double get(Point P) {
        if (isMundefine) return P.x - x;
        return P.y - m * P.x - c;
    }
};

bool isMiddle(Point P1, Point P2, Point P3) {
    double r = P1.Distance(P2);
    return abs(P1.Distance(P3) + P2.Distance(P3) - r) < ERROR;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long testCase;
    cin >> testCase;
    Point P1, P2, P3, P4;
    while (testCase--) {

        P1.takePoint();
        P2.takePoint();
        P3.takePoint();
        P4.takePoint();

        Line L1(P1, P2), L2(P3, P4);

        if (L1.isSame(L2)) {
            if (P1.Distance(P2) > P3.Distance(P4)) {
                if (isMiddle(P1, P2, P3) or isMiddle(P1, P2, P4)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
            else {
                if (isMiddle(P3, P4, P2) or isMiddle(P3, P4, P1)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }

        }
        else if (L1.get(P3)*L1.get(P4) <= ERROR and L2.get(P1)*L2.get(P2) <= ERROR) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }
    return 0;
}

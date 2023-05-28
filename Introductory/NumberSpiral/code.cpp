#include <iostream>
using namespace std;

long long Number(long long x, long long y) {
    long long row, index;
    if (x > y) {
        row = x;
        index = y;
    } else {
        row = y;
        index = (y << 1) - x;
    }

    if (row % 2 == 1) {
        row--;
        return row * row + index;
    }
    return row * row - index + 1;
}

int main() {
    long long testCase, x, y;
    cin >> testCase;
    while (testCase--) {
        cin >> x >> y;
        cout << Number(x, y) << "\n";
    }
    return 0;
}
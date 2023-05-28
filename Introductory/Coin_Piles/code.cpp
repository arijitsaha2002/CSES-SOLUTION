#include <iostream>
using namespace std;

int main() {
    long testCase, a, b;
    cin >> testCase;
    while (testCase > 0) {
        cin >> a >> b;
        if ((a+b) % 3 == 0 and (max(a,b) <= 2*min(a,b))) cout << ("YES") << endl;
        else cout << ("NO") << endl;
        testCase--;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long total = n * (n + 1) / 2;
    long long halfTotal = total / 2;
    string S1 = "", S2 = "";
    if (total % 2 == 0) {
        cout << ("YES") << endl;
        long t = 0;
        long a = 0, b = 0;
        while (halfTotal != 0) {
            if (halfTotal < n) {
                t = halfTotal;
                S1 += " " + to_string(t);
                a++;
                break;
            }
            S1 += " " + to_string(n);
            a++;
            halfTotal -= n;
            n--;
        }
        cout << (a) << endl;
        cout << (S1.substr(1, S1.length())) << endl;
        while (n > 0) {
            if (n != t) {
                b++;
                S2 += to_string(n) + " ";
            }
            n--;
        }
        cout << (b) << endl;
        cout << (S2.substr(0, S2.length() - 1)) << endl;

    } else {
        cout << ("NO") << endl;
    }
    return 0;
}
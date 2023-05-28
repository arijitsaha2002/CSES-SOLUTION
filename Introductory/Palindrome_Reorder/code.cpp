#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> M;
    for (char c : s) {
        M[c] = M[c] + 1;
    }

    bool isMid = false;
    char c;
    string m = "";
    int t;
    s = "";
    unordered_map<char, int>::iterator I = M.begin();

    for (; I != M.end(); I++) {
        c = I->first;
        t = I->second;

        if (t % 2 == 0) {
            t = (t >> 1);
            for (int j = 0; j < t; j++) {
                s += c;
            }
        } else {
            if (isMid) {
                cout << ("NO SOLUTION") << endl;
                return 0;
            }
            t = (t >> 1);
            for (int j = 0; j < t; j++) {
                s += c;
            }
            isMid = true;
            m = c;
        }
    }
    string p = s;
    reverse(p.begin(),p.end());
    s = s + m + p;
    cout << (s) << endl;
    return 0;
}

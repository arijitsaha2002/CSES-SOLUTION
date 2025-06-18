#include <iostream>
#include <algorithm>
using namespace std;

int counts[26];

int main() {
    string s ,ans, middle = "";
    cin >> s;
    for(auto c : s) {
        counts[c - 'A'] ++;
    }
    for (int i = 0; i < 26; i ++) {
        if (counts[i] & 1 and middle == "") {
            counts[i] --;
            middle = i + 'A';
        }
        else if (counts[i] & 1) {
            cout << "NO SOLUTION\n";
            return 0;
        }

        for(int j = 0 ; 2*j < counts[i]; j++) {
            ans.push_back(i + 'A');
        }
    }
    cout << ans << middle;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char last = '$';
    long max_longest = 0, current_longest = 0;
    for(auto &c : s) {
        if(c == last) {
            current_longest++;
        } else {
            current_longest = 1;
        }
        max_longest = max(max_longest, current_longest);
        last = c;
    }
    cout << max_longest << endl;
    return 0;
}

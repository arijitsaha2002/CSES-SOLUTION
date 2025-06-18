#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;

    string s;
    size_t counter = 0;

    while (n) {
        s = to_string(n);
        n -= *max_element(s.begin(), s.end()) - '0';
        counter ++;
    }

    cout << counter << endl;

    return 0;
}

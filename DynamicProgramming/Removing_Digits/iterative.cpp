#include <iostream>
#include <vector>
#include <cassert>
using namespace std;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    size_t n;
    cin >> n;
    vector<size_t> Table(n + 1,n+1);
    Table[0] = 0;
    string s;
    size_t minValue;

    for (size_t i = 1; i <= n; i++) {
        s = to_string(i);
        minValue = 1 + Table[i - (s[0] - '0')];
        for (size_t j = 1; j < s.size(); j++) {
            minValue = min(minValue, 1 + Table[i - (s[j] - '0')]);
        }
        Table[i] = minValue;
    }

    cout << Table[n] << endl;

    return 0;
}

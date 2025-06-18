#include <iostream>
using namespace std;

const int MaxN = 4e6;
int pi_array[MaxN];

int main() {

    string str, pattern;
    cin >> str;
    cin >> pattern;
    string s = pattern + "*" + str;

    int i = 1, len = 0;
    while (i < s.size()) {
        if (s[i] == s[len]) pi_array[i++] = ++len;
        else if (len == 0) pi_array[i++] = 0;
        else len = pi_array[len - 1];
    }

    i = 0;
    for(int j = pattern.size(); j < s.size(); j++) i += (pi_array[j] == pattern.size());
    cout << i << endl;
    return 0;
}
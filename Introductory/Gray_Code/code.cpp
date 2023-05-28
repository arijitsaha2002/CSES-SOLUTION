#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> Recursion(int n) {
    if (n == 1) return {"0", "1"};
    vector<string> S1,S0 = S1 = Recursion(n - 1);
    reverse(S1.begin(), S1.end());
    for_each(S1.begin(), S1.end(), [&](string &s) { s = "1" + s; });
    for_each(S0.begin(), S0.end(), [&](string &s) { s = "0" + s; });
    S0.insert(S0.end(), S1.begin(), S1.end());
    return S0;
}

int main() {
    int n;
    cin >> n;
    vector<string> s = Recursion(n);
    for_each(s.begin(),s.end(),[](string &a){cout << a << endl;});    
    return 0;
}
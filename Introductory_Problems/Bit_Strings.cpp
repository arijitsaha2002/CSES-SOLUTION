#include <iostream>
using namespace std;

const long MOD = 1e9 + 7;

int main() {
    long n;
    cin >> n;
    long answer = 1, mult = 2;
    while(n) {
        if (n & 1) {
            answer = (answer * mult) % MOD;
        }
        mult = (mult * mult) % MOD;
        n = n >> 1;
    }
    cout << answer << endl;
    return 0;
}    

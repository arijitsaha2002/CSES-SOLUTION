#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (long i = 1; i <= t; i++) {
        cout << i*i * (i*i - 1) / 2 - 4*(i - 1)*(i - 2)<< endl;
    }
    return 0;
}    

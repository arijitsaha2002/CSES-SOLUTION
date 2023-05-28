#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define N 1000000007



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;

    size_t a1 = 1, a2 = 1, a3 = 0, a4 = 0, a5 = 0, a6 = 0, temp;

    for(size_t i = 1; i < n; i++){
        temp = a1 + a2 + a3 + a4 + a5 + a6;
        a6 = a5 % N;
        a5 = a4 % N;
        a4 = a3 % N;
        a3 = a2 % N;
        a2 = a1 % N;
        a1 = temp % N;
    }

    cout << a1 % N << endl;
    
    return 0;
}
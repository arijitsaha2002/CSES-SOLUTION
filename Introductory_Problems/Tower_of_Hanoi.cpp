#include <iostream>
using namespace std;

void solve(int n, int start, int middle, int end) {
    if (n == 1) {
        cout << start << " " << end << "\n";
    } else {
        solve(n - 1, start, end, middle);
        cout << start << " " << end << "\n";
        solve(n - 1, middle, start, end);
    }
}    

int main() {
    int n;
    cin >> n;
    cout << (1<<n) - 1 << "\n";
    solve(n, 1, 2, 3);
}    

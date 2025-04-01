#include <iostream>
using namespace std;


int main() {
    long n, x;
    cin >> n;
    long number_of_moves = 0;
    long current_largest_number = 0;
    while(n --) {
        cin >> x;
        current_largest_number = max(current_largest_number, x);
        number_of_moves += (current_largest_number - x);
    }
    cout << number_of_moves << endl;
    return 0;
}    

#include <iostream>
using namespace std;

void print_bit_strings(int n, string prefix = "", bool is_reverse = false) {
    if(n == 0){
        cout << prefix << "\n";
        return;
    } 
    if (is_reverse) {
        print_bit_strings(n - 1, prefix + "1");
        print_bit_strings(n - 1, prefix + "0", true);
    } else {
        print_bit_strings(n - 1, prefix + "0");
        print_bit_strings(n - 1, prefix + "1", true);
    }
}    

int main () {
    int n;
    cin >> n;
    print_bit_strings(n);
    return 0;
}    

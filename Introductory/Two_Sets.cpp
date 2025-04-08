#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    if(n % 4 == 0) {
        cout << "YES\n" << n / 2 << "\n";
        for (int i = 1; i <= n; i ++) {
            if (abs(n + 1 - 2*i) % 4 == 1) {
                cout << i << " ";
            }
        }
        cout << "\n" << n / 2 << "\n";
        for (int i = 1; i <= n; i ++) {
            if (abs(n + 1 - 2*i) % 4 == 3) {
                cout << i << " ";
            }
        }
    } else if (n % 4 == 3) {
        n -= 3;
        cout << "YES\n" << n / 2  + 2 << "\n";
        cout << 1 << " ";
        for (int i = 1; i <= n; i ++) {
            if (abs(n + 1 - 2*i) % 4 == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << n + 2 << " \n" << n / 2 + 1 << "\n";
        for (int i = 1; i <= n; i ++) {
            if (abs(n + 1 - 2*i) % 4 == 3) {
                cout << i + 1 << " ";
            }
        }
        cout << n + 3;
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}    

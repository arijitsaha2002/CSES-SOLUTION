#include <iostream>
using namespace std;

#define newline '\n'

int main() {

    int n = 100;

    long long m = 1, i = 0;

    // while (m) {

    //     cout << m << " ";
    //     m *= (n - i);
    //     i ++;
    //     m /= i;

    // }

    // ------------------ (1-x)^-n -------------

    m = 1;

    for (int r = 1; r < 600; r ++) {

        cout << m << " ";

        m *= (n + r - 1);
        m /= r;

    }

    cout << endl;

    cout << newline;
    
    return 0;
}

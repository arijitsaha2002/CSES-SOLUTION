#include <iostream>
#include <numeric>
using namespace std;

const int N = 1e5;

int main() {
    bool A[N];
    cout << accumulate(A, A + N, 0LL) << endl;
    return 0;
}

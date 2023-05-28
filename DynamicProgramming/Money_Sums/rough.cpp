#include <iostream>
#include <numeric>
using namespace std;

const int N = 1e9;

bool A[N];

int main() {
    cout << accumulate(A, A + N, 0LL) << endl;
    return 0;
}

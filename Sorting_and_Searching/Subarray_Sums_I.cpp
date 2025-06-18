#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    long long m;
    cin >> n >> m;
    vector<long long> A(n);
    for_each(A.begin(), A.end(), [](long long & s) { cin >> s; });


    long i = 0, j = 0, counter = 0;
    long long sum = 0;

    while (j < A.size()) {
        if (i == A.size() + 1 and sum <= m) {
            break;
        }

        counter += (sum == m);

        if (sum < m) {
            sum += A[i];
            i ++;
        } else {
            sum -= A[j];
            j ++;
        }
        
    }

    cout << counter << endl;
    return 0;
}

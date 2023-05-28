#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<long long int> arr(n);

    for (int h = 0; h < arr.size(); h++) cin >> arr[h];

    long long int total = 0;
    for (int j = 0; j < n; j++) total += arr[j];

    bitset<20> A;
    long long int i = 0, l = (1 << (n - 1)), k;
    n --;
    long long int minSum = total, s;
    while (i < l) {
        A = i;
        s = 0;
        for (int j = 0; j < n; j++) s += arr[j] * A.test(j);
        s <<= 1;
        k = total - s;
        k = (k > 0) ? k : -k;
        minSum = (minSum > k) ? k : minSum;
        i++;
    }
    cout << minSum << endl;
    return 0;
}
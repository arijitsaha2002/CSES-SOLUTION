#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, counter = 0, sum = 0;
    long long x;

    cin >> n >> x;

    vector<long long>A(n);

    for_each(A.begin(), A.end(), [](long long & s) { cin >> s; });

    map<long long, long> Table;
    Table[0] = 1;

    for (long i = 0; i < A.size(); i++) {
        sum += A[i];
        counter += Table[sum - x];
        Table[sum] ++;
    }

    cout << counter << endl;

    return 0;
}

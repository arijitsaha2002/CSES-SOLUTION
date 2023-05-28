#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, counter;
    long long x;

    cin >> n >> x;

    vector<long long>A(n);
    for_each(A.begin(), A.end(), [](long long & s) { cin >> s; });

    vector<unordered_map<long long, long>> Table(n + 1,unordered_map<long long, long>(n));
    long long sum = 0, target;
    long long total = accumulate(A.begin(), A.end(), 0);
    unordered_map<long long, long> temp;

    if (total == x) counter ++;

    for (long i = A.size() - 1; i > -1 ; i--) {
        temp[total] ++;
        Table[i + 1] = temp;
        total -= A[i];
    }

    temp[total];
    Table[0] = temp;

    counter += Table[0][x];
    sum = 0;

    cout << "done" << endl;

    for (long i = 1; i < Table.size(); i++) {
        sum += A[i - 1];
        target = sum + x;
        counter += Table[i][target];
    }

    cout << counter << endl;

    return 0;
}

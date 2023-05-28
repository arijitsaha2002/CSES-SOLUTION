#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

long long m;

long long findMin(long long v, vector<long long> &Table) {

    if(v < 0 or v > m){
        cout << v << " " << m << endl;
        assert(false);
    }

    if (v == 0) return 0;
    else if (Table[v] != -1) return Table[v];

    long long minValue = (long long) INFINITY;
    string s = to_string(v);

    for (auto digit : s) {
        long long t = atol(&digit);
        if (t != 0) {
            minValue = min(minValue, 1 + findMin(v - t, Table));
        }
    }

    Table[v] = minValue;
    return minValue;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    m = n;
    vector<long long> Table(n+1, -1);
    cout << findMin(n, Table) << endl;
    return 0;
}

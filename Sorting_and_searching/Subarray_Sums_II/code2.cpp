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
    long long x, t;

    cin >> n >> x;

    unordered_map<long long, long> Table;
    
    Table[0] = 1;

    for (long i = 0; i < n; i++) {
        
        cin >> t;
        sum += t;
        
        if (Table.find(sum - x) != Table.end()) {
            counter += Table[sum - x];
        }

        Table[sum] ++;
    }

    cout << counter << endl;

    return 0;
}

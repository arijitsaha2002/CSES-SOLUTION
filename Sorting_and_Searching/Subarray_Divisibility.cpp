#include <iostream>
#include <vector>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, m, counter = 0;
    cin >> n;
    m = n;

    vector<long long> Table(n, 0);
    Table[0] = 1;

    long long t, sum = 0;

    while (n--) {

        cin >> t;
        sum += m + t % m;
        sum %= m;
        counter += Table[sum];
        Table[sum] ++;

    }

    cout << counter << endl;



    return 0;
}

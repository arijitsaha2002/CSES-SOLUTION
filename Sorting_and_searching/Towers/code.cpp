#include <iostream>
#include <set>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n;
    cin >> n;
    long long temp;
    cin >> temp;
    multiset<long long>B;
    B.insert(temp);

    for (long i = 1; i < n; i ++) {

        cin >> temp;
        auto l = B.upper_bound(temp);
        B.insert(temp);
        if (l != B.end()) B.erase(l);

    }

    cout << B.size() << endl;

    return 0;
}

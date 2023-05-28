#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long> X(n);
    for_each(X.begin(), X.end(), [](long & p) { cin >> p;});

    vector<long> S;

    S.push_back(X[0]);

    for (int i = 1; i < n; i++) {
        auto it = lower_bound(S.begin(), S.end(), X[i]);
        if ( it == S.end()) {
            S.push_back(X[i]);
        }
        else {
            *it = X[i];
        }
    }

    cout << S.size() << newline;
    return 0;
}
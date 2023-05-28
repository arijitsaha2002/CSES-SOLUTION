#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

    vector<long> Table(n, 0);

    Table[0] = 1;

    for (int i = 1; i < n; i++) {

        Table[i] = 1;

        for (int j = 0; j < i; j++) {

            if (X[i] > X[j]) {

                Table[i] = max(Table[i],Table[j] + 1);

            }

        }

    }

    cout << * max_element(Table.begin(), Table.end()) << newline;
    return 0;
}
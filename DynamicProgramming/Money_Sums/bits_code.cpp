#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;

#define ll long long

const int M = 100002;

bitset<M> Table;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> N(n);

    // bitset<M> Table;

    for_each(N.begin(), N.end(), [](int &p) { cin >> p; });


    
    Table.set(0);
    int total = 0;

    for (int j = 0; j < N.size(); j++) {
        total += N[j];
        for (int i = total; i >= N[j]; i--) {
            if(Table.test(i - N[j])) Table.set(i);
        }
    }


    // cout << Table.count() - 1 << "\n";
    total ++;
    for (int i = 1; i <= total ; i++) {
        if (Table.test(i)) cout << i << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
using namespace std;

#define ll long long

const int M = 100002;

bool Table[M];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> N(n);

    for_each(N.begin(), N.end(), [](int &p) { cin >> p; });


    
    Table[0] = 1;
    int total = 0;

    for (int j = 0; j < N.size(); j++) {
        total += N[j];
        for (int i = total; i >= N[j]; i--) {
            if(Table[i - N[j]]) Table[i] = true;
        }
    }


    cout << accumulate(Table + 1, Table + M, 0LL) << "\n";
    total ++;
    for (int i = 1; i <= total ; i++) {
        if (Table[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
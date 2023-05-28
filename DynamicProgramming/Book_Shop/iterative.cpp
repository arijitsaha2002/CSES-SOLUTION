#include <bits/stdc++.h>
using namespace std;

// #define int long long

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> pages(n), price(n);

    for_each(price.begin(), price.end(), [](int &p) { cin >> p;});
    for_each(pages.begin(), pages.end(), [](int &p) { cin >> p;});


    vector<vector<int>> Table(n, vector<int>(x + 1, 0));
    for (int j = x ; j >= 0; j--) {
        if (j >= price[n - 1]) Table[n - 1][j] = pages[n - 1];
    }


    for (int i = n - 2; i >= 0 ; i--) {
        for (int j = x ; j >= 0; j--) {
            Table[i][j] = Table[i + 1][j];
            if (j >= price[i]) {
                Table[i][j] = max(Table[i][j], pages[i] + Table[i + 1][j - price[i]]);
            }
        }
    }

    cout << Table[0][x] << endl;

    return 0;
}
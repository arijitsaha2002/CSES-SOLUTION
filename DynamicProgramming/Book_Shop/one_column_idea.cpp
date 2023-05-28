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


    vector<int> Table(x + 1, 0);
    for (int j = x ; j >= 0; j--) {
        if (j >= price[n - 1]) Table[j] = pages[n - 1];
    }


    for (int i = n - 2; i >= 0 ; i--) {
        for (int j = x ; j >= price[i]; j--) {
            Table[j] = max(Table[j], pages[i] + Table[j - price[i]]);
        }
    }

    cout << Table[x] << endl;

    return 0;
}
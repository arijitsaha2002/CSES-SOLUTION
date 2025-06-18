#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    uint16_t n;
    uint32_t x;
    cin >> n >> x;
    vector<uint16_t> pages(n), price(n);

    for_each(price.begin(), price.end(), [](uint16_t &p) { cin >> p;});
    for_each(pages.begin(), pages.end(), [](uint16_t &p) { cin >> p;});


    vector<uint32_t> Table(x + 1, 0);
    for (int32_t j = x ; j >= price[n - 1]; j--) {
        Table[j] = pages[n - 1];
    }


    for (int16_t i = n - 2; i >= 0 ; i--) {
        for (int32_t j = x ; j >= price[i]; j--) {
            Table[j] = max(Table[j], pages[i] + Table[j - price[i]]);
        }
    }

    cout << Table[x] << endl;

    return 0;
}
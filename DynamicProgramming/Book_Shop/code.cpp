#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long

int maxValue;

int getMax(int i, int x, vector<vector<int>> &Table, vector<int> &price, vector<int> &pages) {
    if (x < 0) return -pages[i+1];
    if (i < 0 ) return 0;
    if (Table[i][x] != -1) return Table[i][x];


    Table[i][x] = max(getMax(i - 1, x, Table, price, pages), getMax(i - 1, x - price[i], Table, price, pages) + pages[i]);
    return Table[i][x];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    maxValue = x;
    vector<int> pages(n), price(n);

    for_each(price.begin(), price.end(), [](int &p) { cin >> p;});
    for_each(pages.begin(), pages.end(), [](int &p) { cin >> p;});


    vector<vector<int>> Table(n + 1, vector<int>(x + 1, -1));
    cout << getMax(n-1, x, Table, price, pages) << endl;


    return 0;
}
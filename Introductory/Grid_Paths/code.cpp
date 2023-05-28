#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '

const int n = 7;

bool arr[n][n];

int get_total(int x, int y, int length, string s) {

    if (x < 0 or x >= n or y < 0 or y >= n ) return 0;


    if (arr[x][y]) return 0;
    arr[x][y] = 1;


    if ( x == 0 and y == n - 1 ) {
        arr[x][y] = 0;
        return (length == (n * n - 1));
    }


    int l = get_total(x - 1, y, length + 1, s + "l") + get_total(x, y - 1, length + 1, s + "u");
    l += get_total(x + 1, y, length + 1, s + "r") + get_total(x, y + 1, length + 1, s + "d");

    arr[x][y] = 0;
    return l;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << get_total(0, 0, 0,"") << newline;

    return 0;
}
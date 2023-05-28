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
const int actual_length = (n * n - 1);

bool arr[n][n];

bool is_outside(int x, int y) {
    return (x < 0 or x >= n or y < 0 or y >= n );
}

int ans = 0;

char s[50];

void get_total(int x, int y, int length) {

    if ( (x == 0 and y == n - 1 ) or (length >= actual_length)) {
        ans += (length == actual_length);
        return;
    }

    if ((is_outside(x + 1, y) || arr[x + 1][y]) && (is_outside(x - 1, y) || arr[x - 1][y]))
        if (!is_outside(x, y - 1) && !arr[x][y - 1] && !is_outside(x, y + 1) && !arr[x][y + 1])
            return;
    if ((is_outside(x, y + 1) || arr[x][y + 1]) && (is_outside(x, y - 1) || arr[x][y - 1]))
        if (!is_outside(x + 1, y) && !arr[x + 1][y] && !is_outside(x - 1, y) && !arr[x - 1][y])
            return;


    arr[x][y] = 1;
    char c = s[length];

    length ++;

    if (c == 'D' or c == '?') {
        if (!is_outside(x, y + 1) and !arr[x][y + 1] ) get_total(x, y + 1, length);
    }
    if (c == 'U' or c == '?') {
        if (!is_outside(x, y - 1) and !arr[x][y - 1] ) get_total(x, y - 1, length);
    }
    if (c == 'R' or c == '?') {
        if (!is_outside(x + 1, y) and !arr[x + 1][y] ) get_total(x + 1, y, length);
    }
    if (c == 'L' or c == '?') {
        if (!is_outside(x - 1, y) and !arr[x - 1][y] ) get_total(x - 1, y, length);
    }


    arr[x][y] = 0;
    return;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    get_total(0, 0, 0);
    cout <<  ans << newline;

    return 0;
}
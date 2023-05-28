#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    double u = 1, d = pow(k, n), prev = 1, curr;

    for (int i = 2; i <= k; i++) {
        curr = pow(i, n);
        u += i * (curr - prev);
        prev = curr;
    }

    u /= d;

    printf("%.6f\n", u);
    return 0;
}
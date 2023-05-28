#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <stdio.h>
using namespace std;

#define ll long long
#define M 1000000007

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;

    cin >> n >> x >> y;

    vector<unordered_map<int, double>> Table(101, unordered_map<int, double>());

    for (int i = 1; i < 7; i++) {
        Table[1][i] = 1;
    }


    for (int j = 2; j < n + 1; j++) {
        for (int i = 1; i < 7; i++) {
            for (auto t : Table[j - 1]) {
                Table[j][t.first + i] += t.second;
            }
        }
    }

    double a = 0;
    double total = 0;
    for (auto t : Table[n]) {
        if (t.first <= y && t.first >= x) {
            a += t.second;
        }
        total += t.second;
    }

    a /= total;

    printf("%.6f\n", a);
    return 0;
}
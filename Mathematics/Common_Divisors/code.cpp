#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define newline '\n'
const int M = 1e6 + 1;

int arr[M], mult[M];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x] ++;
    }


    for (int i = M; i > 0; i--) {
        for (int j = i; j < M; j += i) {
            if (arr[j]) {
                mult[i] += arr[j];
            }
        }
        if (mult[i] > 1) {
            cout << i << newline;
            return 0;
        }

    }

    return 0;
}
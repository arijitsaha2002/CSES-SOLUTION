#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    long arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long i = 0, j = 1, sum = arr[0], max_sum = accumulate(arr, arr + b, 0L);

    while (j <= n and i < n) {

        // cout << i << "        " << j << endl;

        if (j - i > b) {
            sum -= arr[i];
            i ++;
            // continue;
        }
        else if (j - i < a) {
            if ( j == n) break;
            sum += arr[j];
            j ++;
            // continue;
        }
        else if ( sum >= 0 and j < n) {
            sum += arr[j];
            j ++;
        }
        else {
            sum -= arr[i];
            i ++;
        }

        if ( j - i <= b and j - i >= a) {
            max_sum = max(max_sum, sum);
        }
        // cout << "----loop----" << endl;
    }

    while (i < n and j - i >= a) {

        if (j - i > b) {
            sum -= arr[i];
            i ++;
            // continue;
        }
        else {
            sum -= arr[i];
            i ++;
            max_sum = max(max_sum, sum);
        }
    }


    cout << max_sum << endl;

    return 0;
}
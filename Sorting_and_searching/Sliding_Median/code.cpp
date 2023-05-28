#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>

struct cmp {
    bool operator() (const Point &P1, const Point &P2) const {
        return (P1.first < P2.first) || ((P1.first == P2.first) && (P1.second < P2.second));
    }
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    Point arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    tree<Point, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> T(arr, arr + k);


    for (int i = k ; i < n; i ++) {
        int s = (T.size() - 1) >> 1;
        cout << T.find_by_order(s)->first << blankchar;
        T.erase(arr[i - k]);
        T.insert(arr[i]);
    }

    int s = (T.size() -1 ) >> 1;
    cout << T.find_by_order(s)->first << blankchar << endl;

    return 0;
}
#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 2e5 + 4;
const int root = sqrt(MaxN);
int Count[MaxN];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    point arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n);

    int hash = 0, prev = arr[0].first;
    for (int i  = 0; i < n; i ++) {
        if (arr[i].first == prev) {
            arr[i].first = hash;
        }
        else {
            hash ++;
            prev = arr[i].first;
            arr[i].first = hash;
        }
    }


    sort(arr, arr + n, [](point p1, point p2) {
        return p1.second < p2.second;
    });


    vector<vector<int>> Q(q, vector<int>(3));

    for (int i = 0; i < q; i ++) {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][2] = i;
        Q[i][0] --;
        Q[i][1] --;
    }

    sort(Q.begin(), Q.end(), [](vector<int> v1, vector<int> v2) {
        if (v1[0] / root == v2[0] / root) {
            return v1[1] < v2[1];
        }
        return (v1[0] / root) < (v2[0] / root);
    });


    vector<int> ans(q);
    int size = 1, l = 0, r = 0;
    Count[arr[l].first]++;

    for (auto a : Q) {

        while (l < a[0]) {
            if (Count[arr[l].first] == 1) size --;
            Count[arr[l].first] --;
            l ++;
        }

        while (l > a[0]) {
            l --;
            if (Count[arr[l].first] == 0) size ++;
            Count[arr[l].first] ++;
        }


        while (r < a[1]) {
            r ++;
            if (Count[arr[r].first] == 0) size ++;
            Count[arr[r].first] ++;
        }

        while (r > a[1]) {
            if (Count[arr[r].first] == 1) size --;
            Count[arr[r].first] --;
            r --;
        }

        ans[a[2]] = size;
    }

    for (auto a : ans) {
        cout << a << newline;
    }
    return 0;
}
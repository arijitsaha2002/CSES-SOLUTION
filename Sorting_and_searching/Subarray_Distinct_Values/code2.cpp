#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 2e5 + 1;
int COUNTER[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;

    cin >> n >> k;
    Point arr[n];
    FOR(i, n) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n, [](const Point &p1, const Point &p2) { return p1.first < p2.first; });

    int hash_value = 0, prev = arr[0].first;
    arr[0].first = hash_value;

    for (int i = 1; i < n; i++) {
        if (arr[i].first == prev) {
            arr[i].first = hash_value;
        } else {
            prev = ++hash_value;
            swap(arr[i].first, prev);
        }
    }

    sort(arr, arr + n, [](Point &p1, Point &p2) { return p1.second < p2.second; });

    ll i = 0, j = 0, r = (((n + 1) * n ) >> 1);

    COUNTER[arr[0].first] = 1;
    int s = 1;

    while (j < n) {
        if (s > k) {
            r -= (n - j);
            if (COUNTER[arr[i].first] == 1) {
                COUNTER[arr[i].first] = 0;
                s--;
            } else {
                COUNTER[arr[i].first]--;
            }
            i++;
        } else {
            j++;
            if (!COUNTER[arr[j].first]) {
                s++;
            }
            COUNTER[arr[j].first]++;
        }
    }

    cout << r << endl;

    return 0;
}
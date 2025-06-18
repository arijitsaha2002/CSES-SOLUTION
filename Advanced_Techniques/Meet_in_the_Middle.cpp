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

const int MaxN = 41;
int arr[41];
int n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    INPUT(n, arr);

    bitset<20> N;
    N = 0;

    unordered_map<int, int> S1(2e6);
    for (int i = 0; i < (1 << (n / 2)); i ++) {
        N = i;
        int sum = 0;
        for (int j = 0; j < n / 2; j++) {
            if (N.test(j)) sum += arr[j];
        }
        S1[sum] ++;
    }

    S1[0] = 1;

    unordered_map<int, int> S2(2e6);
    for (int i = 0; i < (1 << (n - n / 2)); i ++) {
        N = i;
        int sum = 0;
        for (int j = 0; j < (n - n / 2); j++) {
            if (N.test(j)) sum += arr[j + n / 2];
        }
        S2[sum] ++;
    }

    S2[0] = 1;

    int result = 0;
    for (auto s1 : S1) {
        auto it = S2.find(m - s1.first);
        if (it != S2.end()) {
            result += (s1.second * it->second);
        }
    }


    cout << result << endl;
    return 0;
}
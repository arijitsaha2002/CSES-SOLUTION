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

int cp(point v1, point v2) {
    return (v1.first * v2.second - v1.second * v2.first);
}

point sub(point p1, point p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

int dist(point p1, point p2) {
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return x * x + y * y;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    point arr[n];

    for (int i = 0; i < n; i ++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n);
    point base = arr[0];

    sort(arr + 1, arr + n, [base](point p1, point p2) {
        int ans = cp(sub(p1, base), sub(p2, base));
        if (ans == 0) return dist(p1, base) < dist(p2, base);
        return ans < 0;
    });

    vector<point> A(arr, arr + n);

    sort(A.begin() + 1, A.end(), [base](point p1, point p2) {
        int ans = cp(sub(p1, base), sub(p2, base));
        if (ans == 0) return dist(p1, base) > dist(p2, base);
        return ans <= 0;
    });

    auto last = arr[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == last) {
            arr[i] = A[i];
            break;
        }
        if (A[i] != arr[i]) {
            arr[i] = A[i];
        }
    }

    vector<point> ans;
    ans.push_back(base);
    ans.push_back(arr[1]);


    for (int i = 2; i < n; i ++) {
        while (cp(sub(ans[ans.size() - 2], ans.back()), sub(arr[i], ans.back())) < 0) {
            ans.pop_back();
        }
        ans.push_back(arr[i]);
    }

    sort(ans.begin(), ans.end());


    cout << ans.size() << newline;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << blankChar << ans[i].second << newline;
    }
    return 0;
}
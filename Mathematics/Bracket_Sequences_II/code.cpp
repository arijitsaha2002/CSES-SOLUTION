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

long power(long a, long b) {
    long r = 1, m = a;
    while (b) {
        if (b & 1) r = (r * m) % M;
        b >>= 1;
        m = (m * m) % M;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0;
    for (auto c : s) {
        if (c == '(') l++;
        else {
            l--;
            n -= 2;
        }


        if (l < 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (l < 0 or n < 0 or n & 1) {
        cout << 0 << endl;
        return 0;
    }

    ll m = n - l;
    n >>= 1;
    n -= l;

    ll ne = (m + 1 - 2 * n), de = (m + 1 - n), i = n + 1, j = m - n;

    while (j > 0) {
        de = (de * j) % M;
        ne = (ne * i) % M;
        i++;
        j--;
    }

    cout << (ne * power(de, M - 2)) % M << newline;

    return 0;
}
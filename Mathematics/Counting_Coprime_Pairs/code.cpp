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

const int MaxN = 1e6 + 1;
ll divisor[MaxN];
ll counter[MaxN];

void fill() {
    divisor[1] = 1;
    for (int i = 2; i < MaxN; i++) {
        if (!divisor[i]) {
            for (int j = i; j < MaxN; j += i) {
                divisor[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill();

    ll n, l;
    cin >> n;

    ll t;
    FOR(i, n) {
        cin >> t;
        int p = t;
        while (t > 1) {
            l = divisor[t];
            counter[t]++;
            while (t > 1 and l == divisor[t]) {
                t /= l;
                counter[t]++;
            }
        }
    }

    ll r = 0;

    for (int i = 2; i < MaxN; i++) {
        if (counter[i] > 1) {
            r += ((counter[i] - 1) * counter[i]) >> 1;
        }
    }

    cout << (((n - 1) * n) >> 1) - r << newline;

    return 0;
}
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

const int MaxN = 2e6;
ll List[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    int W[n];
    INPUT(n, W);

    sort(W, W + n);

    ll N = (1 << n);
    bitset<22> Bit_N;

    for (ll i = 1; i < N; i++) {
        Bit_N = i;
        for (ll j = 0; j < n; j++) {
            if (Bit_N[j]) List[i] += W[j];
        }
    }

    ll r = 0, curr = 0;
    while (curr != N - 1) {
        r ++;
        ll max_value = 0, index = 0;
        for (ll j = 1; j < N; j++) {
            if ((curr & j) == 0) {
                if (List[j] >= max_value and List[j] <= m) {
                    max_value = List[j];
                    index = j;
                }
            }
        }
        curr = (curr | index);
    }

    cout << r << endl;

    return 0;
}
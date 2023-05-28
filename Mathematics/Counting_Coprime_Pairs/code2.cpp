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
                if(!divisor[j]) divisor[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill();

    ll t, l;
    cin >> t;

    l = 1;
    while (t > l) {
        t /= l;
        l = divisor[t];
        counter[t]++;
        counter[l]++;
        cout << t << " " << l << endl;
    }

    for (int i = 2; i < MaxN; i++) {
        if (counter[i]) {
            cout << i << blankchar << newline;
        }
    }

    return 0;
}
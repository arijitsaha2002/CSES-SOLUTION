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

ll Power(ll a, ll b) {
    ll result = 1, multiplier = a;
    while (b) {
        if (b & 1) {
            result *= multiplier;
            result %= M;
        }
        multiplier *= multiplier;
        multiplier %= M;
        b >>= 1;
    }
    return result;
}

const int MaxN = 1e6 + 1;
ll fact[MaxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MaxN; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }
}

ll char_count[130];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    string s;
    cin >> s;

    for (auto c : s) {
        char_count[c]++;
    }

    ll ne = fact[s.size()];
    ll de = 1;

    for (int i = 0; i < 130; i++) {
        de *= fact[char_count[i]];
        de %= M;
    }

    cout << (ne * Power(de, M - 2)) % M << endl;

    return 0;
}
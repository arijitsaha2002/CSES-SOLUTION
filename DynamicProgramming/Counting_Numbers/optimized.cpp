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

ll power[22];

ll recursion(int index, bool is_restricted, string &s, char prev, vector<vector<ll>> &Table) {
    if (index >= s.size()) {
        return 1;
    }

    if (is_restricted) {
        if (Table[index][prev]) {
            return Table[index][prev];
        }

        ll r = 0;
        for (char i = '0'; i < s[index]; i++) {
            if (i != prev) {
                if (prev == '$' and i == '0') {
                    r += recursion(index + 1, false, s, prev, Table);
                } else {
                    r += recursion(index + 1, false, s, i, Table);
                }
            }
        }
        if (s[index] != prev) {
            if (prev == '$' and s[index] == '0') {
                r += recursion(index + 1, true, s, prev, Table);
            } else {
                r += recursion(index + 1, true, s, s[index], Table);
            }
        }
        Table[index][prev] = r;
        return r;

    } else {
        if (prev == '$') {
            ll r = 0;
            for (char i = '0'; i <= '9'; i++) {
                if (i != prev) {
                    if (i == '0') {
                        r += recursion(index + 1, false, s, prev, Table);
                    } else {
                        r += recursion(index + 1, false, s, i, Table);
                    }
                }
            }
            return r;
        }
        else{
            return power[index];
        }        
    }
}

ll solve(string r) {
    if (r == "0") return 1;

    power[r.size()] = 1;

    for (int i = r.size() - 1; i > -1; i--) {
        power[i] = power[i + 1] * 9LL;
    }

    vector<vector<ll>> Table(22, vector<ll>(200, 0));

    return recursion(0, true, r, '$', Table);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;
    if (l == 0) {
        cout << solve(to_string(r)) << endl;
    } else {
        cout << solve(to_string(r)) - solve(to_string(l - 1)) << endl;
    }

    return 0;
}
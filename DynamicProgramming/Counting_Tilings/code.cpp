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

int n, m;
vector<string> valid_str;

ll Table[5742][1001];
bool is_valid[5742][5742];

void find_valid(vector<string> &vi, int index, string s, char prev) {
    if (index == n) {
        if (prev != '2') {
            vi.push_back(s);
        }
    } else if (index < n) {
        if (prev == '2') {
            find_valid(vi, index + 1, s + "3", '3');
        } else {
            for (char i = '0'; i < '3'; i++) {
                find_valid(vi, index + 1, s + i, i);
            }
        }
    }
}

bool is_valid_checker(string left, string right) {
    for (int i = 0; i < right.size(); i++) {
        if (left[i] == '0' xor right[i] == '1') {
            return false;
        }
    }
    return true;
}
string init = "111111111111111111111111111111111111111111111111111111111";

ll count(int i, int k) {
    if (Table[i][k]) {
        cout << "come " << endl;
        return Table[i][k];
    }
    if (k == 0) {
        if (is_valid_checker(init, valid_str[i])) {
            return 1;
        } else {
            return 0;
        }
    }
    ll r = 0;
    for (int j = 0; j < valid_str.size(); j++) {
        if (is_valid[j][i]) {
            r += count(j,k - 1);
            r %= M;
        }
    }

    Table[i][k] = r;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    find_valid(valid_str, 0, "", '_');

    for (int i = 0; i < valid_str.size(); i++) {
        for (int j = 0; j < valid_str.size(); j++) {
            if (is_valid_checker(valid_str[i], valid_str[j])) {
                is_valid[i][j] = true;
            }
        }
    }

    cout << count(0, m) << endl;

    return 0;
}
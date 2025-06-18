#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


const int MaxN = 4e6;
int dp[MaxN];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, str = "&";
    cin >> s;

    for (char c : s) {
        str += "#";
        str += c;
    }
    str += "#$";
    dp[2] = 1;

    int l = 1, r = 3, i = 3;
    while (i < str.size()) {

        if ( i < r) {
            dp[i] = min(dp[2 * l - i], r - i);
        }

        while (i + dp[i] + 1 < str.size() and i > dp[i] and str[i - dp[i] - 1] == str[i + dp[i] + 1]) {
            dp[i] ++;
        }

        if (i + dp[i] > r) {
            l = i;
            r = i + dp[i];
        }

        i ++;
    }

    auto it = max_element(dp, dp + str.size());
    int v = *it;
    int index = it - dp;

    string ans = str.substr(index - v, 2*v), a = "";
        
    for(auto c : ans){
        if(c != '#'){
            a += c;
        }
    }
    cout << a << endl;
    return 0;
}
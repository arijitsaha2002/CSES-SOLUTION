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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int l = (1 << n);
    string s = "";

    for (int i = 0; i < n; i++) s += "0";

    set<string> S;
    string r = s;

    // cout << s << endl;
    S.insert(s);

    for(int i = 1; i < l; i++) {

        string t = s.substr(1, n);

        if (S.find((t + "1")) == S.end()) {
            s = (t + "1");
            r += "1";
            S.insert(s);
        } 
        else {
            r += "0";
            s = (t + "0");
            S.insert(s);
        }
        S.insert(s);
    }

    cout << r << endl;
    return 0;
}
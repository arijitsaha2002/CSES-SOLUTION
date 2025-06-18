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

const int MaxN = 1e6 + 4;
int z[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    for(int i = 1, l = 0, r = 0; i < str.size(); i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < str.size() and str[z[i]] == str[i + z[i]]) z[i] ++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }

    for(int i = 1; i < str.size(); i++){
        if(z[i] + i == str.size()) cout << i << blankChar;
    }
    cout << str.size() << endl;

    return 0;
}
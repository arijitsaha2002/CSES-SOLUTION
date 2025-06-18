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

const int MaxN = 2e6;
int pi_array[MaxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int i = 1, len = 0;
    while(i < str.size()){
        if(str[i] == str[len]) pi_array[i++] = ++len;
        else if(len == 0) pi_array[i++] = 0;
        else len = pi_array[len - 1];
    }

    stack<int> P;
    int curr = pi_array[str.size() - 1];
    while (curr != 0) {
        P.push(curr);
        curr = pi_array[curr - 1];
    }

    for(; not P.empty(); P.pop()){
        cout << P.top() << blankChar;
    }
    cout << endl;
    return 0;
}
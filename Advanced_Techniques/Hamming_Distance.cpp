#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define int long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define point pair<int, int>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int hamming(int a, int b){
    int c = a ^ b;
    return bitset<32>(c).count();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    string s;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> s;
        arr[i] = bitset<32>(s).to_ulong();
    }


    int min_value = INT_MAX;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j++){
            min_value = min(min_value, hamming(arr[i], arr[j]));
        }
    }

    cout << min_value << endl;
    return 0;
}
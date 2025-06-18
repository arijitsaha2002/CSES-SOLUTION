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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll a = 0, b = 1, t;
    
    for(int i = 2; i < n; i ++){
        t = (i * (a + b)) % M;
        a = b;
        b = t;
    }
    
    cout << b << endl;
    return 0;
}
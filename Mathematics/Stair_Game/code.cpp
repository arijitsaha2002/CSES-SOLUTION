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

    ll testCase, n, r, t;
    cin >> testCase;

    while(testCase --){
        
        r = 0;
        
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> t;

            if(i & 1){
                r ^= t;
            }
        }

        if(r) cout << "first" << newline;
        else cout << "second" << newline;
    }
    
    return 0;
}
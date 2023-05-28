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

    string s;
    cin >> s;
    
    int n;
    cin >> n;

    string arr[n];
    INPUT(n,arr);

    map<string, int> Table;

    for(int i = 0; i < n; i ++){
        
        Table[arr[i]] ++;

        for(int j = 0; j < n; j++){
            
        }
    }
    
    return 0;
}
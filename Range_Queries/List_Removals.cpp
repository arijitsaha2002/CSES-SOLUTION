#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
    int arr[n];

    INPUT(n, arr);

    tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

    for(int i = 0; i < n; i++){
        T[i] = arr[i];
    }

    int a;
    while(n --){
        cin >> a;
        a --;
        auto it = T.find_by_order(a);
        cout << it->second << blankchar;
        T.erase(it);
    }

    cout << newline;    
    return 0;
}
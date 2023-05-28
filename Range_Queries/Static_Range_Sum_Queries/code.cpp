#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline ' '
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];

    FOR(i, n) cin >> arr[i];

    ll sums[n + 1];
    sums[0] = 0;

    for(int i = 0; i < n; i ++){
        sums[i + 1] = sums[i] + arr[i];
    }

    int a, b;

    while(m --){
        cin >> a >> b;
        cout << sums[b] - sums[a - 1] << newline;
    }
    
    return 0;
}
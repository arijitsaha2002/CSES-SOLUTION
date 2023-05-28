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

bool is_possible(ll *sum, int n, int value, int k){

    ll prev = 0;
    
    auto end = sum + n;
    auto it = sum;
    
    for(int i = 0; i < k and it != end; i ++){
        it = upper_bound(sum, sum + n, prev + value);
        if(it != sum) prev = *(it - 1);
        else return 0;
    }

    return (it == end);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, value;
    cin >> n >> m >> value;

    ll int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0) cout << "yes" << endl;
    }

    ll sum[n];
    sum[0] = arr[0];

    // for(int i = 1; i < n; i++){
    //     sum[i] = arr[i] + sum[i - 1];
    //     if(arr[i] < 0) cout << "yes" << endl;
    // }

    // cout << (is_possible(sum, n, value, m)) << endl;

    return 0;
}
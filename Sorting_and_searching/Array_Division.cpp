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
 
bool is_possible(ll *sum, ll n, ll value, ll k){
 
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
 
    ll n, m;
    cin >> n >> m;
 
    ll arr[n];
    INPUT(n,arr);
    ll sum[n];
    sum[0] = arr[0];
 
    for(int i = 1; i < n; i++){
        sum[i] = arr[i] + sum[i - 1];
    }
 
    ll left = arr[0], right = sum[n - 1], mid;
 
    while(left < right - 1){
        mid = (left + right) >> 1;
        if(is_possible(sum, n, mid, m)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
 
    cout << right << endl;
 
    return 0;
}

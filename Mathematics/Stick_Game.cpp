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

const int MaxN = 1e6 + 1;
bool dp[MaxN];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    int arr[k];
    INPUT(k, arr);

    sort(arr, arr + k);
    dp[0] = false;

    for(int i = 1; i <= n; i++){
        dp[i] = false;
        for(int j = 0; j < k and arr[j] <= i; j++){
            if(not dp[i - arr[j]]){
                dp[i] = true;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dp[i]){
            cout << "W";
        }
        else{
            cout << "L";
        }
    }
    cout << endl;
    return 0;
}
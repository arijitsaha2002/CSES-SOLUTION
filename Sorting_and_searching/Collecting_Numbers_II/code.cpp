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

    int n, m;
    cin >> n >> m;

    int arr[n + 2], index[n + 2];
    arr[0] = 0, arr[n + 1] = INT_MAX;
    index[0] = 0, index[n + 1] = INT_MAX;


    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        index[arr[i]] = i;
    }

    int c = 1;
    for(int i = 2 ; i <= n; i++){
        if(index[i] < index[i - 1]){
            c ++;
        }
    }

    int i, j;
    while(m --){
        t = 0;

        cin >> i >> j;

        c -= (index[arr[i]] < index[arr[i] - 1]) + (index[arr[i] + 1] < index[arr[i]]);
        c -= (index[arr[j]] < index[arr[j] - 1]) + (index[arr[j] + 1] < index[arr[j]]);
        
        if(abs(arr[i] - arr[j]) <= 1){
            c += index[max(arr[i], arr[j])] < index[min(arr[i], arr[j])];
        }

        swap(index[arr[i]], index[arr[j]]);

        c += (index[arr[i]] < index[arr[i] - 1]) + (index[arr[i] + 1] < index[arr[i]]);
        c += (index[arr[j]] < index[arr[j] - 1]) + (index[arr[j] + 1] < index[arr[j]]);
        if(abs(arr[i] - arr[j]) <= 1){
            c -= index[max(arr[i], arr[j])] < index[min(arr[i], arr[j])];
        }        
        swap(arr[i], arr[j]);
        cout << c << newline;

    }

    return 0;
}
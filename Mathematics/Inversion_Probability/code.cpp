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

    double R[n];
    INPUT(n, R);

    double ans = 0; 

    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j++){
            
            double t = (min(R[i], R[j]) - 1) / (2 * max(R[i], R[j]));

            if(R[i] > R[j]){
                t += (R[i] - R[j]) / R[i];
            }

            ans += t;

        }
    }

    ans = round(ans * 1e7) / (1e7);
    printf("%.6f\n", ans);
    
    return 0;
}
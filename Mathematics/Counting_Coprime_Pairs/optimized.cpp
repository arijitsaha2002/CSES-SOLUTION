#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e6 + 1;
ll divisor[MaxN];
bool is_odd[MaxN];
bool is_visited[MaxN];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, t; cin >> n;
    FOR(i, 0, n){
        cin >> t;
        divisor[t] ++;
    }

    for(int i = 2; i < MaxN; i++){
        for(int j = 2*i; j < MaxN; j += i ){
            divisor[i] += divisor[j];
        }
    }

    for(ll i = 2; i < MaxN; i++){
        if(!is_visited[i]){
            for(int j = i; j < MaxN; j+= i){
                is_visited[j] = true;
                is_odd[j] = !is_odd[j];
                if(j % (i * i) == 0) divisor[j] = 0;
            }
        }
    }



    ll r = n * (n - 1) / 2;

    for(int i = 2; i < MaxN; i++){
        if(divisor[i] > 1){
            if(is_odd[i]){
                r -= (divisor[i] - 1) * divisor[i] / 2;
            }
            else{
                r += (divisor[i] - 1) * divisor[i] / 2;
            }
        }
    }

    cout << r << endl;
    
    return 0;
}
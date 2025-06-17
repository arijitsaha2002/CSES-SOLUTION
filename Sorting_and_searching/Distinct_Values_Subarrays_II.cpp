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
 
    ll n, k;
 
    cin >> n >> k;
    ll arr[n];
    INPUT(n, arr);
 
    ll i = 0, j = 0, r = 0;
    map<ll, int> S;
    S[arr[0]] = 1;
 
    while (j < n) {
        if (S.size() > k) {
            r += (n - j);
            if (S[arr[i]] <= 1) {
                S.erase(arr[i]);
            }
            else{
                S[arr[i]] --;
            }
            i++;
        } else {
            j++;
            S[arr[j]]++;
        }
    }
 
    cout << (n + 1) * n / 2 - r << endl;
 
    return 0;
}


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
vector<vector<ll>> divisors(MaxN, vector<ll>());
ll Counter[MaxN];
bool paired[MaxN];

void fill() {
    for (int i = 2; i < MaxN; i++) {
        if (divisors[i].size() == 0) {
            for (int j = i; j < MaxN; j += i) {
                divisors[j].push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill();

    ll n;
    cin >> n;
    ll arr[n];
    INPUT(n, arr);

    ll r = n * (n - 1) / 2;

    for (int i = 0; i < n; i++) {
        for (ll j = (1 << divisors[arr[i]].size()) - 1; j > 0 ; j--) {
            ll m = 1;
            int c = 0;
            for (ll k = 0; k < divisors[arr[i]].size(); k++) {
                if (j & (1 << k)) {
                    m *= divisors[arr[i]][k];
                    c++;
                }
            }
            Counter[m]++;
            if (c & 1) paired[m] = 1;
            else paired[m] = 0;
        }
    }

    for(int i = 2; i < MaxN; i++){
        if(Counter[i] > 1){
            if(paired[i]){
                r -= (Counter[i] * (Counter[i] - 1)) >> 1;
            }
            else{
                r += (Counter[i] * (Counter[i] - 1)) >> 1;
            }
        }
    }

    cout << r << endl;
    return 0;
}
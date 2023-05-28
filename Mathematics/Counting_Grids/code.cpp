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

ll Power(ll a, ll b){
    b %= (M - 1);
    ll result = 1, multiplier = a;
    while(b){
        if(b & 1){
            result *= multiplier;
            result %= M;
        }
        multiplier = (multiplier * multiplier) % M;
        b >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    if(n == 1){
        cout << 2 << endl;
    }
    else if (n & 1) {

        ll nn = n * n;
        ll half_n = n / 2;
        ll total = Power(2,nn - 2);
        ll d2 = Power(2, (nn + 1)/2 - 2 );
        ll d4 = Power(2, half_n * (half_n + 1));
        ll f = (total + d4 + d2) % M;
        cout << f << endl;
    } else {
        ll nn = n * n;
        ll total = Power(2,nn - 2);
        ll d2 = Power(2,(nn / 2) - 2);
        ll d4 = Power(2, (nn / 4) - 1);
        ll f = (total + d4 + d2) % M;
        cout << f << endl;
    }

    return 0;
}
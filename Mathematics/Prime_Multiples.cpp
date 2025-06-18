#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

#define ll long long
#define M 1000000007

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    ll k;
    cin >> n >> k;

    ll arr[k];

    for (int i = 0; i < k; i++) cin >> arr[i];

    ll N = (1LL << k) - 1;
    bitset<22> Bin_N = N;

    ll result = 0, m;
    double t;

    while ( N ) {
        Bin_N = N;
        

        m = 1;
        t = 1;
        bool isDone = false;

        for (int i = 0; i < k; i++) {
            if (Bin_N[i]) {
                if(t * arr[i] > n){
                    isDone = true;
                    break;
                }
                m *= arr[i];
                t *= arr[i];
            }
        }

        if(isDone) {
            N --;
            continue;
        }

        if (Bin_N.count() & 1) {
            result += (ll)(n/m);
        }
        else {           
            result -= (ll)(n/m);
        }        

        N --;
    }


    cout << result << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define pi                              acos(-1.0)
#define rep(i, a, n)                    for (int i = a; i < n; i++)
#define per(i, a, n)                    for (int i = n - 1; i >= a; i--)
#define Long                            long long
#define all(x)                          (x).begin(), (x).end()
 
const int Nn = 100002;
int MOD = 1e9 + 7;
 
bool DP[Nn];
 
void solve(int tc) {
    int n;
    cin >> n;
 
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    
    DP[0] = true;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += A[i];
        for (int j = tot; j >= A[i]; --j) if (DP[j - A[i]]) DP[j] = true;
    }
 
    cout << accumulate(DP + 1, DP + Nn, 0) << "\n";
    for (int i = 1; i < Nn; ++i) if (DP[i]) cout << i << " ";
    cout << endl;
}
 
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T = 1; //cin >> T;
    for (int i = 1; i <= T; ++i) solve(i);
 
    return 0;
}
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
#define ADD(a, b) (a == LONG_LONG_MAX or b == LONG_LONG_MAX ? LONG_LONG_MAX : a + b)
int n, m, p;

ll Matrix[101][101];
ll TEMP[101][101];
ll Result[101][101];
bool is_set = false;
void EXP(int l) {
    while (l) {
        // FOR(i, 1, n + 1) {
        //     FOR(j, 1, n + 1) { cout << Matrix[i][j] << blankchar; }
        //     cout << endl;
        // }

        // cout << "check" << endl;

        if (l & 1) {
            if (is_set) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        TEMP[i][j] = LONG_LONG_MAX;
                        for (int k = 1; k <= n; k++) {
                            TEMP[i][j] = min(TEMP[i][j], ADD(Result[i][k], Matrix[k][j]));
                        }
                    }
                }

                swap(TEMP, Result);
            } else {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        Result[i][j] = Matrix[i][j];
                    }
                }
                is_set = true;
            }
        }
        l >>= 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                TEMP[i][j] = LONG_LONG_MAX;
                for (int k = 1; k <= n; k++) {
                    TEMP[i][j] = min(TEMP[i][j], ADD(Matrix[i][k], Matrix[k][j]));
                }
            }
        }

        // FOR(i, 1, n + 1) {
        //     FOR(j, 1, n + 1) { cout << Matrix[i][j] << blankchar; }
        //     cout << endl;
        // }

        // cout << "check" << endl;
        swap(TEMP, Matrix);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            Matrix[i][j] = LONG_LONG_MAX;
        }
    }

    ll a, b, c;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        Matrix[b][a] = min(Matrix[b][a], c);
    }
    // FOR(i, 1, n + 1) {
    //     FOR(j, 1, n + 1) { cout << Result[i][j] << blankchar; }
    //     cout << endl;
    // }
    // cout << "------" << newline;

    EXP(p);

    // FOR(i, 1, n + 1) {
    //     FOR(j, 1, n + 1) { cout << Result[i][j] << blankchar; }
    //     cout << endl;
    // }
    cout << (Result[n][1] == LONG_LONG_MAX ? -1 : Result[n][1]) << endl;
    return 0;
}
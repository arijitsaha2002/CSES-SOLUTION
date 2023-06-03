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
int n, m, p;

ll Matrix[101][101];
ll TEMP[101][101];
ll Result[101][101];

void EXP(int l) {
    while (l) {
        if (l & 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    TEMP[i][j] = 0;
                    for (int k = 1; k <= n; k++) {
                        TEMP[i][j] += Result[i][k] * Matrix[k][j];
                        TEMP[i][j] %= M;
                    }
                }
            }

            swap(TEMP, Result);
        }
        l >>= 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                TEMP[i][j] = 0;
                for (int k = 1; k <= n; k++) {
                    TEMP[i][j] += Matrix[i][k] * Matrix[k][j];
                    TEMP[i][j] %= M;
                }
            }
        }

        swap(TEMP, Matrix);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;

    int a, b;
    FOR(i, 0, m) {
        cin >> a >> b;
        Matrix[b][a] ++;
    }

    for(int i = 1; i <= n; i++){
        Result[i][i] = 1;
    }

    EXP(p);
    cout << Result[n][1] << endl;
    return 0;
}
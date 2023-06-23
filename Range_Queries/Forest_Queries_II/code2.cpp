#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++);
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 3001;
long Tree[MaxN][MaxN];
bool arr[1001][1001];
int n, m;

void build_col(int row, int r, int node, int low, int high){
    if(low == high){
        Tree[r][node] = arr[row][low];
    }
    else if( low < high){
        int childLeft = node << 1;
        int childRight = childLeft + 1;
        int mid = (low + high) >> 1;
        build_col(row, r, childLeft, low, mid);
        build_col(row, r, childRight, mid + 1, high);
        Tree[r][node] = Tree[r][childLeft] + Tree[r][childRight];
    }
}

void build_row(int node, int low, int high) {
    if (low == high) {
        build_col(low, node, 1, 0, n - 1);
    }
    else if (low < high) {
        int childLeft = node << 1;
        int childRight = childLeft + 1;
        int mid = (low + high) >> 1;
        build_row(childLeft, low, mid);
        build_row(childRight, mid + 1, high);

        for (int i = 0; i <= MaxN; i++) {
            Tree[node][i] = Tree[childLeft][i] + Tree[childRight][i];
        }
    }
}

int queries_col(int row, int r, int node, int low, int high){
    
}

int queries_row(int node, int low, int high){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    char c;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> c;
            arr[i][j] = (c == '*');
        }
    }




    int a, b, d, e, t;

    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            // update(1, 0, 0, n - 1, n - 1, a - 1, b - 1);
        } else {
            cin >> a >> b >> d >> e;
            a--, b--, d--, e--;
            // cout << queries(1, 0, 0, n - 1, n - 1, a, b, d, e) << newline;
        }
    }

    return 0;
}
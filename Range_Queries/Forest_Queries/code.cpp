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

long tree[(int)(2e7)];

void build(int node, string arr[], int x1, int y1, int x2, int y2){
    if(x1 == x2 and y1 == y2){
        tree[node] = (arr[x1][y1] == '*');
    }
    else if(x1 <= x2 and y1 <= y2){
        int mid_x = (x1 + x2) >> 1;
        int mid_y = (y1 + y2) >> 1;
        int child = node << 2;
        build(child, arr, x1, y1, mid_x, mid_y);
        build(child + 1, arr, mid_x + 1, y1, x2, mid_y);
        build(child + 2, arr, x1, mid_y + 1, mid_x, y2);
        build(child + 3, arr, mid_x + 1, mid_y + 1, x2, y2);
        tree[node] = tree[child] + tree[child + 1] + tree[child + 2] + tree[child + 3];
    }
}

int queries(int node, int x1_, int y1_, int x2_, int y2_, int x1, int y1, int x2, int y2){
    if(x1_ <= x1 and y1_ <= y1 and x2_ >= x2 and y2_ >= y2){
        return tree[node];
    }
    else if( x2_ < x1 or x2 < x1_ or y1_ > y2 or y2_ < y1){
        return 0;
    }
    else{
        int mid_x = (x1 + x2) >> 1;
        int mid_y = (y1 + y2) >> 1;
        int child = node << 2;
        int q1 = queries(child,x1_, y1_, x2_, y2_ ,x1, y1, mid_x, mid_y);
        int q2 = queries(child + 1,x1_, y1_, x2_, y2_ ,mid_x + 1, y1, x2, mid_y);
        int q3 = queries(child + 2,x1_, y1_, x2_, y2_ ,x1, mid_y + 1, mid_x, y2);
        int q4 = queries(child + 3,x1_, y1_, x2_, y2_ ,mid_x + 1, mid_y + 1, x2, y2);
        
        return q1 + q2 + q3 + q4;
    }
}    

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string arr[n];
    INPUT(n, arr);

    build(1, arr, 0, 0, n - 1, n - 1);

    int a, b, c, d;

    while(m--){
        cin >> a >> b >> c >> d;
        a --, b--, c--, d--;
        cout << queries(1, a, b, c, d, 0, 0, n - 1, n - 1) << newline;
    }


    return 0;
}
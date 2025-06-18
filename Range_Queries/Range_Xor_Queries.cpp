#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; i++){ cin >> arr[i];}
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int tree[(const int)6e6];

void build(int node, int *arr, int low, int high){
    if(low == high) tree[node] = arr[low];
    else if(low < high){
        int mid = (low + high) >> 1;
        int child = node << 1;
        build(child, arr, low, mid);
        build(child + 1, arr, mid + 1, high);
        tree[node] = tree[child] ^ tree[child + 1];
    }
}

int queries(int node, int left, int right, int low, int high){
    if(left <= low and high <= right){
        return tree[node];
    }
    else if(high < left or low > right){
        return 0;
    }
    else{
        int mid = (low + high) >> 1;
        int child = node << 1;
        int ql = queries(child, left, right, low, mid);
        int qr = queries(child + 1, left, right, mid + 1, high);
        return ql ^ qr;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[n];
    INPUT(n, arr);

    build(1, arr, 0, n - 1);

    int a, b;
    while(m --){
        cin >> a >> b;
        a --, b--;
        cout << queries(1, a, b, 0, n - 1) << newline;
    }
    
    return 0;
}
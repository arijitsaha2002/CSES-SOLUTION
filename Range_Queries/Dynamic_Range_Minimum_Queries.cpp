#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; i++) cin >> arr[i];
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int tree[(int)(6e6)];   

void build(int node, int* arr, int low, int high){
    if(low == high) tree[node] = arr[low];
    if(low < high){

        int mid = (low + high) >> 1;
        int child = node << 1;

        build(child, arr, low, mid);
        build(child + 1, arr, mid + 1, high);

        tree[node] = min(tree[child], tree[child + 1]);
    }

}

int queries(int node, int low, int high, int left, int right){
    if(left <= low and high <= right) return tree[node];
    if(left > high or right < low) return INT_MAX;

    int mid = (low + high) >> 1;
    int child = (node << 1);

    int ql = queries(child, low, mid, left, right);
    int qr = queries(child + 1,mid + 1, high, left, right);
    return min(ql, qr);
}

void update(int node, int low, int high, int index, int value){
    if(low > index or high < index) return;
    if(low == high){
        if(low == index) tree[node] = value;
    }
    if(low < high){
        int mid = (low + high) >> 1;
        int child = (node << 1);
        update(child, low, mid, index, value);
        update(child + 1, mid + 1, high, index, value);
        tree[node] = min(tree[child], tree[child + 1]);
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

    int type, a, b;
    while (m --) {
        cin >> type >> a >> b;
        a --;
        if(type == 1){
            update(1, 0, n - 1, a, b);
        }
        else{
            b --;
            cout << queries(1, 0, n - 1, a, b) << newline;
        }
    }

    
    
    return 0;
}
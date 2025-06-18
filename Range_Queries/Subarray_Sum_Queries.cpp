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

const int MaxN = 1e6;
long Tree[MaxN][4];

void build(long *arr, int node, int left, int right) {
    if (left == right) {
        Tree[node][0] = arr[left];
        Tree[node][1] = arr[left];
        Tree[node][2] = arr[left];
        Tree[node][3] = arr[left];
    }
    else if (left < right) {
        int childLeft = 2 * node;
        int childRight = 2 * node + 1;
        int mid = (left + right) >> 1;
        build(arr, childLeft, left, mid);
        build(arr, childRight, mid + 1, right);
        Tree[node][3] = Tree[childLeft][3] + Tree[childRight][3];
        Tree[node][2] = max(Tree[childRight][2], Tree[childLeft][2] + Tree[childRight][3]);
        Tree[node][1] = max(Tree[childLeft][1], Tree[childRight][1] + Tree[childLeft][3]);
        Tree[node][0] = max(Tree[childLeft][0], Tree[childRight][0]);
        Tree[node][0] = max(Tree[node][0], Tree[childLeft][2] + Tree[childRight][1]);
    }
}

void update(int node, int left, int right, int index, int value) {
    if (left == right) {
        if (left == index) {
            Tree[node][0] = value;
            Tree[node][1] = value;
            Tree[node][2] = value;
            Tree[node][3] = value;
        }
    }
    else if ( left <= index and index <= right) {
        int childLeft = 2 * node;
        int childRight = 2 * node + 1;
        int mid = (left + right) >> 1;
        update(childLeft, left, mid, index, value);
        update(childRight, mid + 1, right, index, value);
        Tree[node][3] = Tree[childLeft][3] + Tree[childRight][3];
        Tree[node][2] = max(Tree[childRight][2], Tree[childLeft][2] + Tree[childRight][3]);
        Tree[node][1] = max(Tree[childLeft][1], Tree[childRight][1] + Tree[childLeft][3]);
        Tree[node][0] = max(Tree[childLeft][0], Tree[childRight][0]);
        Tree[node][0] = max(Tree[node][0], Tree[childLeft][2] + Tree[childRight][1]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    long arr[n];
    INPUT(n, arr);
    build(arr, 1, 0, n - 1);


    int a, b;
    while (m --) {
        cin >> a >> b;
        update(1, 0, n - 1, a - 1, b);
        cout << max(Tree[1][0], 0L) << newline;
    }
    return 0;
}
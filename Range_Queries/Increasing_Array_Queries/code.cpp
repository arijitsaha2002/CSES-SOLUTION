#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;",
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define blankChar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MaxN = 1e6;
long Tree[MaxN][4];

void build(long * arr, int node, int low, int high) {
    if (low == high) {
        Tree[node][0] = 1;
        Tree[node][1] = 0;
        Tree[node][2] = arr[low];
        Tree[node][3] = arr[high];
    }
    else if (low < high) {
        int childLeft = node << 1;
        int childRight = childLeft + 1;
        int mid = (low + high) >> 1;
        build(arr, childLeft, low, mid);
        build(arr, childRight, mid + 1, high);
        Tree[node][0] = Tree[childRight][0] + Tree[childLeft][0];

        if (Tree[childLeft][2] <= Tree[childRight][3]) {
            Tree[node][1] = Tree[childLeft][1] + Tree[childRight][1];
            Tree[node][2] = Tree[childRight][2];
        }
        else {
            Tree[node][1] = Tree[childLeft][1] + (Tree[childLeft][2] - Tree[childRight][3]) * Tree[childRight][0] + Tree[childRight][1];
            Tree[node][2] = Tree[childRight][2] + (Tree[childLeft][2] - Tree[childRight][3]);
        }

        Tree[node][3] = Tree[childLeft][3];

        // cout << "low " << low << " high " << high << blankChar << Tree[node][1] << endl;
    }
}


array<long, 4> queries(int node, int left, int right, int low, int high) {
    array<long, 4> temp = {0, 0, 0, 0};
    if (low <= high) {
        if (left <= low and high <= right) {
            return {Tree[node][0], Tree[node][1], Tree[node][2], Tree[node][3]};
        }
        else if (right < low or left > high) {
            cout << "blank" << low << blankChar << high << endl;
            return temp;
        }
        else {

            cout << low << blankChar << high << endl;

            int childLeft = node << 1;
            int childRight = childLeft + 1;
            int mid = (low + high) >> 1;

            array<long, 4> Left = queries(childLeft, left, right, low, mid);
            array<long, 4> Right = queries(childLeft, left, right, mid + 1, high);


            temp[0] = Left[0] + Right[0];

            if (Left[2] <= Right[3]) {
                temp[1] = Left[1] + Right[1];
                temp[2] = Right[2];
            }
            else {
                temp[1] = Left[1] + (Left[2] - Right[3]) * Right[0] + Right[1];
                temp[2] = Right[2] + (Left[2] - Right[3]);
            }

            temp[3] = Left[3];
            return temp;
        }
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    long arr[n];
    INPUT(n, arr);
    build(arr, 1, 0, n - 1);

    int a, b;
    while (q --) {
        cin >> a >> b;
        cout << queries(1, a - 1, b - 1, 0, n - 1)[1] << newline;
    }

    return 0;
}
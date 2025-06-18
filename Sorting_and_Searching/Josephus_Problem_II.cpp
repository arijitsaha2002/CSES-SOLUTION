#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma unroll 2

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>

int main() {
    int n, k;
    cin >> n >> k;

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

    for (int i = 1; i <= n; i++) {
        T.insert(i);
    }

    int j = 0;
    for (int i  = 0; i < n; i ++) {
        j += k;
        j %= T.size();
        auto it = T.find_by_order(j);
        cout << *it << blankchar;
        T.erase(it);
    }

}
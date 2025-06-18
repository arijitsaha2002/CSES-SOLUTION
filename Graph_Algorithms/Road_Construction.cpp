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
#define Point pair<long, long>
#define ADD(a, b) ((a == LONG_MAX or b == LONG_MAX) ? LONG_MAX : a + b)
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


const int MaxN = 1e5 + 2;
int parent_dsu[MaxN];
int size_dsu[MaxN];
int m = INT_MIN;

void make_dsu(int n) {
    if (parent_dsu[n] == 0) {
        parent_dsu[n] = n;
        size_dsu[n] = 1;
        m = max(m, 1);
    }
}

int get_parent(int n) {
    if (parent_dsu[n] == n) return n;
    return parent_dsu[n] = get_parent(parent_dsu[n]);
}

void merge_dsu(int a, int b) {
    a = get_parent(a), b = get_parent(b);
    if (a == b) return;
    if (size_dsu[a] < size_dsu[b]) swap(a, b);
    parent_dsu[b] = a;
    size_dsu[a] += size_dsu[b];
    m = max(m , size_dsu[a]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int>> P;

    int n, q, a, b;
    cin >> n >> q;

    int components = n;

    while(q --){
        cin >> a >> b;
        if(parent_dsu[a] == 0 and parent_dsu[b] == 0) components --;
        else if(get_parent(a) != get_parent(b)) components --;
        make_dsu(a);
        make_dsu(b);
        merge_dsu(a, b);

        cout << components << blankChar << m << newline;
    }


    return 0;
}
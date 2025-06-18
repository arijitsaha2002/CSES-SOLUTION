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
const int MaxEdge = 2e5 + 2;
int parent_dsu[MaxN];
int size_dsu[MaxN];

void make_dsu(int n) {
    if (parent_dsu[n] == 0) {
        parent_dsu[n] = n;
        size_dsu[n] = 1;
    }
}

int find(int n) {
    if (parent_dsu[n] == n) return n;
    parent_dsu[n] = find(parent_dsu[n]);
    return parent_dsu[n];
}

void merge(int a, int b) {
    if (find(a) == find(b)) return;
    if (size_dsu[a] < size_dsu[b]) swap(a, b);
    parent_dsu[find(b)] = find(a);
    size_dsu[a] += size_dsu[b];
}

class Edge {
public:
    long weight, a, b;
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Edge E[m];

    for (int i = 0; i < m; i ++) {
        cin >> E[i].a >> E[i].b >> E[i].weight;
    }

    sort(E, E + m, [](Edge a, Edge b) {return a.weight < b.weight;});

    long result = 0, counter = 0;

    for (auto e : E) {
        make_dsu(e.a);
        make_dsu(e.b);
        if (find(e.a) != find(e.b)) {
            result += e.weight;
            counter ++;
            merge(e.a, e.b);
        }
    }

    if(counter == n - 1){
        cout << result << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
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

const int MaxN = 2e5 + 2;
int dp[MaxN][31];
int root[MaxN];
int dist[MaxN];
int length[MaxN];
bool is_visited[MaxN];
bool is_cycle[MaxN];

int get_next(int a, int b) {
    int node = a, c = 0;
    while (b) {
        if (b & 1) {
            node = dp[node][c];
        }
        c ++;
        b >>= 1;
    }
    return node;
}


void bfs(int node) {
    int curr = node;
    queue<int> S;

    while (not is_visited[curr]) {
        S.push(curr);
        is_visited[curr] = true;
        curr = dp[curr][0];
    }

    if (root[curr] == 0) {
        node = curr;
        for (; not S.empty(); S.pop()) {
            root[S.front()] = node;
        }

        is_cycle[curr] = true;
        dist[curr] = 0;
        curr = dp[curr][0];
        int c = 0;

        while (curr != node) {
            is_cycle[curr] = true;
            dist[curr] = ++c;
            curr = dp[curr][0];
        }

        length[node] = c + 1;
    }
    else {
        if (is_cycle[curr]) {
            node = curr;
        }
        else {
            node = root[curr];
        }
        for (; not S.empty(); S.pop()) {
            root[S.front()] = node;
        }
    }

}


void set_dist(int n) {
    int next = dp[n][0];
    if (is_cycle[next]) {
        dist[n] = 1;
    }
    else {
        if (dist[next] == 0) {
            set_dist(next);
        }
        dist[n] = dist[next] + 1;
    }
}

int get_distance(int a, int b) {
    if (a == b) return 0;
    else if (is_cycle[a] and not is_cycle[b]) {
        return - 1;
    }
    else if (not is_cycle[a] and is_cycle[b]) {
        if (root[root[a]] == root[b]) {
            int v =  get_distance(root[a], b);
            return dist[a] + v;
        }
        else {
            return - 1;
        }
    }
    else if (is_cycle[a] and is_cycle[b]) {
        if (root[a] == root[b]) {
            return (dist[b] - dist[a] + length[root[a]]) % length[root[a]];
        }
        else {
            return - 1;
        }
    }
    else if (root[a] == root[b]) {
        if (dist[a] > dist[b]) {
            int d = dist[a] - dist[b];
            a = get_next(a, d);
            if (a == b) return d;
            else return -1;
        }
        else {
            return - 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> dp[i][0];
    }


    for (int i = 1; i < 31; i ++) {
        for (int node = 1; node <= n; node ++) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (not is_visited[i]) {
            bfs(i);
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (dist[i] == 0 and not is_cycle[i]) {
            set_dist(i);
        }
    }
    int a, b;
    while (m --) {
        cin >> a >> b;
        cout << get_distance(a, b) << newline;

    }

    return 0;
}
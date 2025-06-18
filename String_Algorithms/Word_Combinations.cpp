#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankChar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Node {
public:
    char value;
    bool is_end;
    Node * Adj[26];

    Node(char c = '-') {
        value = c;
        is_end = false;
    }

};


Node Buffer[(const int)1e6];
int Buffer_Counter = 0;

Node *get_Node(char c){
    Buffer[Buffer_Counter].value = c;
    return &Buffer[Buffer_Counter ++];
}

class Trie {
public:

    Node * root;

    Trie() {
        root = get_Node('-');
    }

    void insert(string s) {
        Node * curr = root;

        for (auto c : s) {
            if (curr -> Adj[c - 'a'] == nullptr) {
                curr->Adj[c - 'a'] = get_Node(c);
            }
            curr = curr->Adj[c - 'a'];
        }

        curr -> is_end = true;
    }
};

Trie T;
long dp[5001];
bool is_done[5001];

long dfs(string &s, int start) {

    if (start == s.size()) return 1;
    if (is_done[start]) return dp[start];

    long m = 0;
    Node * curr = T.root;

    for (int i = start; i < s.size(); i ++) {

        curr = curr->Adj[s[i] - 'a'];

        if (curr == nullptr) {
            break;
        }

        if (curr->is_end) {
            m += dfs(s, i + 1);
            m %= MOD;
        }
    }

    dp[start] = m;
    is_done[start] = true;
    return m;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n;
    cin >> n;

    string arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (auto t : arr) {
        T.insert(t);
    }

    cout << dfs(s, 0) << endl;
    return 0;
}
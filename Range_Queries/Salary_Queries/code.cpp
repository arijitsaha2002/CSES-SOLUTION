#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

struct cmp{
    bool operator() (const Point &p1, const Point &p2) const
    {
        return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    Point arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    tree<Point, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> T(arr, arr + n);

    char t;
    int a, b;

    while(m --){
        cin >> t;
        cin >> a >> b;
        if(t == '?'){
            int low = T.order_of_key(Point(a, -1));
            int high = T.order_of_key(Point(b, n));
            cout << high - low << newline;
        }
        else{
            a --;
            T.erase(arr[a]);
            arr[a].first = b;
            T.insert(arr[a]);
        }
    }

    
    return 0;
}
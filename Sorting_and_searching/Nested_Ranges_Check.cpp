#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>
 
 
class Inv {
public:
    int start, end, index;
    Inv(int s, int e, int i) {
        start = s;
        end = e;
        index = i;
    }
    Inv() {}
};
 
 
struct CustomComparator {
    bool operator()(const Inv &a, const Inv &b) const
    {
        if (a.end == b.end) {
            return (a.start > b.start);
        }
        return a.end < b.end;
    }
};
 
struct CustomGreaterComparator {
    bool operator()(const Inv &a, const Inv &b) const
    {
        if (a.end == b.end) {
            return (a.start < b.start);
        }
        return a.end > b.end;
    }
};
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> A(n, 0), B(n, 0);
 
    vector<Inv> S(n);
 
    tree<Inv, null_type, CustomComparator, rb_tree_tag, tree_order_statistics_node_update> T;
 
    for (int i = 0; i < n; i++) {
        cin >> S[i].start >> S[i].end;
        S[i].index = i;
        T.insert(S[i]);
    }
 
    sort(S.begin(), S.end(), [](Inv &I1, Inv &I2){
        return (I1.start < I2.start) || ((I1.start == I2.start) && (I1.end > I2.end));
    });
 
 
    for (int i = 0; i < n; i++) {
        T.erase(S[i]);
        A[S[i].index] = T.order_of_key(S[i]);
    }
 
    tree<Inv, null_type, CustomGreaterComparator, rb_tree_tag, tree_order_statistics_node_update> Y;
 
    for (int i = 0; i < n; i++) {
        B[S[i].index] = Y.order_of_key(S[i]);
        Y.insert(S[i]);
    }
 
 
    for (auto a : A) cout << (a > 0) << blankchar;
    cout << newline;
    for (auto b : B) cout << (b > 0) << blankchar;
    cout << endl;
 
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
 
#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>
 
class Interval {
public:
    int start, end;
    Interval() {}
    Interval(int s, int e) {
        start = s;
        end = e;
    }
};
 
inline bool cmp(Interval i1, Interval i2) {
    if ((i1.end - i1.start) == (i2.end - i2.start)) {
        return i1.start < i2.start;
    }
    return (i1.end - i1.start) < (i2.end - i2.start);
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int x, n, t; cin >> x >> n;
    set<int> S;
    S.insert(0);
    S.insert(x);
 
    set<Interval, bool(*)(Interval, Interval)> Inv(cmp);
 
    Inv.insert(Interval(0, x));
 
    for (int i = 0; i < n; i++) {
 
        cin >> t;
 
        auto it = S.upper_bound(t);
        int z = *it, y = *(--it);
 
        S.insert(t);
 
        Inv.erase(Interval(y, z));
        Inv.insert(Interval(t, z));
        Inv.insert(Interval(y, t));
 
        Interval largest = *Inv.rbegin();
 
        cout << largest.end - largest.start << blankchar;
 
    }
 
    cout << endl;
 
    return 0;
}

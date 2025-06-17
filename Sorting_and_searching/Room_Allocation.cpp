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
 
class Inv {
public:
    int start, end, index;
 
    Inv() {}
    Inv(int s, int e) {
        start = s;
        end = e;
    }
 
    bool operator < (const Inv i2) const
    {
        return start < i2.start;
    }
 
};
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    multiset<Inv> S;
    Inv A;
 
    int room_allocation[n];
 
    for (int i = 0; i < n; i++) {
        cin >> A.start >> A.end;
        A.index = i;
        S.insert(A);
    }
 
    int room = 1;
    multiset<Inv>::iterator it;
 
    while (S.size()) {
 
        Inv F, K;
        it = S.begin();
 
        do {
 
            F = *it;
            room_allocation[F.index] = room;
            S.erase(it);
            it = S.upper_bound(Inv(F.end, F.end));
 
        } while (it != S.end());
 
        room ++;
 
    }
 
    room --;
 
    cout << room << endl;
 
    for (auto r : room_allocation) {
        cout << r << blankchar;
    }
 
    cout << endl;
 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, x;
    multiset<int> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.begin()) {
            cout << "-1\n";
        } else {
            cout << *(--it) << "\n";
            s.erase(it);
        }
    }
    return 0;
}

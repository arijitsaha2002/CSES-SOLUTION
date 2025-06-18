#include <iostream>
using namespace std;

void solve(){
    long long x, y, min_, max_;
    long long first_element, answer;
    cin >> x >> y;
    min_ = min(x, y);
    max_ = max(x, y);
    if ((x & 1 && x > y) || (!(y & 1) && y > x)) {
        first_element = (max_ - 1) * (max_ - 1) + 1;
        answer = first_element + (min_ - 1);
    }
    else {
        first_element = max_ * max_;
        answer = first_element - (min_ - 1);
    }
    cout << answer << "\n";
}    

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}    



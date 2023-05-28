#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define ll long long

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    uint16_t n;
    cin >> n;
    vector<uint32_t> N(n);

    for_each(N.begin(), N.end(), [](uint32_t &p) { cin >> p; });
    unordered_set<uint32_t> S;

    for (auto a : N) {
        vector<uint32_t> T(S.begin(), S.end());
        for (auto b : T) {
            S.insert(b + a);
        }
        S.insert(a);
    }

    vector<uint32_t> T(S.begin(), S.end());
    sort(T.begin(),T.end());
    cout << T.size() << "\n";
    for(auto c : T){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
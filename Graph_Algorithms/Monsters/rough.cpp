#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    unordered_set<pair<int, int>> S;
    S.insert({4, 6});
    S.insert({5, 7});
    S.insert({6, 8});
    S.insert({7, 9});

    unordered_set<pair<int, int>> T;
    T.insert({6, 9});
    T = S;

    for(auto it: T){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}

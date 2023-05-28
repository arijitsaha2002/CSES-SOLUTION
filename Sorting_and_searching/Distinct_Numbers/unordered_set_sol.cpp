#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long n;
    cin >> n;
    unordered_set<int> M((int)n);
    long temp;
    while(n--){
        cin >> temp;
        M.insert(temp);
    }

    cout << M.size() << endl;
    return 0;
}
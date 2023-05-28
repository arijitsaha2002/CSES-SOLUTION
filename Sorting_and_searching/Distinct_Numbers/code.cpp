#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long n;
    cin >> n;
    unordered_map<int,int> M((int)n);
    long temp;
    for (long i = 0; i < n; i++) {
        cin >> temp;
        M[temp] = 1;
    }

    cout << M.size() << endl;
    return 0;
}
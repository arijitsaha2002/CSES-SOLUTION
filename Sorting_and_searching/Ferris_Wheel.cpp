#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int children, maxWeight;
    cin >> children >> maxWeight;
    vector<int> weights(children);
    for (int i = 0; i < children; i++) cin >> weights[i];
 
    sort(weights.begin(), weights.end());
    int i = 0, j = children - 1, s = 0;
    while (i < j) {
        if (weights[i] + weights[j] <= maxWeight) {
            i++;
            s++;
        }
        j--;
    }
    cout << children - s << endl;
    return 0;
}

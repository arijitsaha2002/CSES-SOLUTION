#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    vector<int> A = {1,2,3,4,5};

    auto l = upper_bound(A.begin(), A.end(), 4);

    if(l == A.end()) cout << "not" << endl;
    else cout << *l << endl;
    
    return 0;
}

#include<iostream>
#include <set>
using namespace std;


int main(){
    set<int> S = {1,2,3,4};

    auto it = S.begin();

    cout << *it << endl;
    S.erase(it);
    cout << *it << endl;
    
    return 0;
}
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


int main() {

    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> T;

    T.insert(7);
    cout << T.size() << endl;
    T.erase(T.lower_bound(7));
    cout << T.size() << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
 
size_t getValue(vector<size_t> &A, size_t t) {
    size_t s = 0;
    for_each(A.begin(), A.end(), [&](size_t &a) { s += t / a;});
    return s;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    size_t n , t;
    cin >> n >> t;
    vector<size_t> A(n);
    for_each(A.begin(), A.end(), [](size_t &a) {cin >> a;});
    size_t right = (* min_element(A.begin(), A.end())) * t, left = 0, mid;
 
    do {
        mid = (left + right) >> 1;
        if(getValue(A,mid) >= t){
            right = mid;
        }
        else{
            left = mid;
        }
    } while( left < right -1 );
 
    cout << right << endl;
 
    return 0;
}

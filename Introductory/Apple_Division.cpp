#include <climits>
#include <iostream>
#include <numeric>
using namespace std;
 
int n;
long p[20];
long total_weight;
 
long get_weight_diff(int distribution) {
    long total_sum = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(distribution & (1<<i)) {
            total_sum += p[i];
        }
    }        
    return abs(total_weight - 2 * total_sum);
}    
 
int main () {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> p[i];
    total_weight = accumulate(p, p + n, 0L);
    long min_diff = LONG_MAX;
    for(long i = 0; i < (1<<(n-1)); i ++) {
        min_diff = min(min_diff, get_weight_diff(i));
    }
    cout << min_diff << endl;
    return 0;
}

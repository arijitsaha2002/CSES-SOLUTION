#include <algorithm>
#include<iostream>
#include <set>
using namespace std;
#define newline '\n'
 
int main(){
    int n;
    cin >> n;
    long arr[n];
    for(auto &a:arr) cin >> a;
    long max_sum = arr[0];
    long current_sum = 0;
    int j = 0;
    while(j < n){
        current_sum += arr[j++];
        if(current_sum > max_sum)
            max_sum = current_sum;
 
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    cout << max_sum << endl;
    return 0;
}

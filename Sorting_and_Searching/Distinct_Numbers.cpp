#include <iostream>
#include <algorithm>
using namespace std;


int main () {
    int n, d = 1, l;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i ++) cin >> arr[i];
    sort(arr, arr + n);
    l = arr[0];
    for(int i = 1; i < n; i ++) {
        if(arr[i] != l) d ++;
        l = arr[i];
    }
    cout << d << endl;
    return 0;
}    

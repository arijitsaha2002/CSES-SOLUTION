#include <algorithm>
#include<iostream>
#include <map>
#include <set>
using namespace std;
#define newline '\n'
 
int main(){
    int n;
    cin >> n;
    long arr[n];
    for(auto &a:arr) cin >> a;
 
    long max_unique = 1, j = 0;
    set<int> present;
    
    for(int i = 0; i < n; i++){
        int current = arr[i];
        if(present.find(current) != present.end()){
            while(arr[j] != current){
                present.erase(arr[j++]);
            }
            present.erase(arr[j++]);
        }
        present.insert(current);
        max_unique = max(max_unique, (long)present.size());
    }
    cout << max_unique << newline;
    return 0;
}

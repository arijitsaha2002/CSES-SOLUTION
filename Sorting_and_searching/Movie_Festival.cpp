#include <algorithm>
#include<iostream>
#include <set>
using namespace std;
#define newline '\n'
 
bool comparator(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second || 
        (a.second == b.second && a.first < b.first);
}
 
int main(){
    int n;
    cin >> n;
    pair<int, int> times[n];
    for(int i = 0; i < n; i++){
        cin >> times[i].first >> times[i].second;
    }
    sort(times, times + n, comparator);
    int counter = 1;
    int last_exit = times[0].second;
    
    int i = 1;
    while(i < n){
        while(i < n and last_exit > times[i].first){
            i ++;
        }
        if (i == n) break;
        last_exit = times[i].second;
        counter ++;
        i ++;
    }
 
    cout << counter << endl;
    return 0;
}

#include <algorithm>
#include<iostream>
#include <set>
using namespace std;
#define newline '\n'

int main(){
    int n;
    cin >> n;
    pair<int, int> times[n];
    for(int i = 0; i < n; i++){
        cin >> times[i].first >> times[i].second;
    }
    sort(times, times + n);
    int counter = 1, max_count = 1;
    multiset<int> outing;
    outing.insert(times[0].second);

    for(int i = 1; i < n; i++){
        auto current = times[i];
        while(outing.size() and *outing.begin() < current.first){
            outing.erase(outing.begin());
            counter --;
        }
        outing.insert(current.second);
        counter ++;
        if(counter > max_count){
            max_count = counter;
        }
    }
    cout << max_count << endl;
    return 0;
}

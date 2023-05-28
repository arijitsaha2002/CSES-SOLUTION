#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<pair<size_t,unsigned long long>> Answer(n+1);
    unsigned long long temp;
    Answer[0].second = 0;
    for(size_t i = 1; i <= n; i ++){
        size_t j = i-1;
        cin >> temp;
        while(Answer[j].second >= temp){
            j = Answer[j].first;
        }
        Answer[i].first = j;
        Answer[i].second = temp;
        cout << j << " ";
    }   

    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n, [](pair<int, int> &p1, pair<int, int> &p2) {return p1.first < p2.first;});

    int c = 1;

    for(int i = 1; i < n; i++){
        if(arr[i].second < arr[i-1].second){
            c ++;
        }
    }

    cout << c << newline;

    return 0;
}
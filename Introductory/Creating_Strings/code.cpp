#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define store(s,arr) for(auto c: arr) s += c; s += "\n" 

int findLeft(vector<char> &arr) {
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) return i - 1;
    }
    return -1;
}

int findRight(vector<char> &arr, char c) {
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i] > c) return i;
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    vector<char> arr(s.begin(), s.end());
    sort(arr.begin(), arr.end());
    s = "";
    store(s,arr);
    int i = 1;
    while (true)
    {
        int l = findLeft(arr);
        if(l == -1) break;
        int r = findRight(arr,arr[l]);
        swap(arr[l],arr[r]);
        l ++;
        reverse(arr.begin()+l,arr.end());
        store(s,arr);
        i ++;
    }
    cout << i << endl;
    cout << s << endl;
    

    return 0;
}
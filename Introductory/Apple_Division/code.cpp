#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int getMin(vector<long long> a){
    int i = 0;
    for(int j = 1; j < a.size(); j++){
        if(a[j] < a[i]) i = j;
    }
    return i;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> brr;
    vector<long long> *a1;
    vector<long long> *a2;

    for (int i = 0; i < arr.size(); i++) cin >> arr[i];
    long long minValue = *min_element(arr.begin(),arr.end());
    long long s1 = accumulate(arr.begin(), arr.end(), 0), s2 = 0;
    
    a1 = &arr;
    a2 = &brr;

    while (abs(s1-s2) > minValue) {
        int m = getMin(*a1);
        if((s1 - s2) >= m){
            a2->push_back((*a1)[m]);
            s2 += (*a1)[m];
            s1 -= (*a1)[m];
            a1->erase(a1->begin()+m);
        }
        else{
            swap(s1,s2);
            swap(a1,a2);
        }
    }

    cout << abs(s1-s2) << endl;
    return 0;
}
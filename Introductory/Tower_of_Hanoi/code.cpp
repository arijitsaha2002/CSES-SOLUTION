#include <iostream>
using namespace std;

void solution(int left, int mid, int right, int size){
    if(size == 0 ) return;
    solution(left,right,mid,size-1);
    cout << left << " " << right << endl;
    solution(mid,left,right,size-1);
}

int main(){
    int n;
    cin >> n;
    cout << (1 << n) -1 << endl;
    solution(1,2,3,n);
    return 0;
}
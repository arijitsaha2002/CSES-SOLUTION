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

    if(n == 1){
        cout << "1" << newline;
        return 0;
    }
    else if(n < 4){
        cout << "NO SOLUTION" << newline;
        return 0;
    }

    for(int i = 2; i <= n; i += 2){
        cout << i << blankchar;
    }
    
    for(int i = 1; i <= n; i += 2){
        cout << i << blankchar;
    }

    cout << newline;
    
    return 0;
}
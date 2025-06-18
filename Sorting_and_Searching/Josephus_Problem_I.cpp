#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>

class Node {
public:
    int value;
    Node * next;
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    Node Arr[n];

    Arr[0].value = 1;

    for (int i = 1; i < n ; i++) {
        Arr[i - 1].next = &Arr[i];
        Arr[i].value = i + 1;
    }

    Arr[n - 1].next = &Arr[0];

    Node * N = &Arr[1], *P = &Arr[0];

    for (int i = 1; i < n; i++) {
        cout << N->value << blankchar;
        P->next = N->next;
        P = N->next;
        N = N->next->next;
    }

    cout << N->value << endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
#define M 1000000007
#define newline '\n'
#define blankchar ' '
#define Point pair<int, int>

class Inv {
public:
    int start, end, index;
    Inv(int s, int e, int i) {
        start = s;
        end = e;
        index = i;
    }
    Inv() {}
};



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, start, end;
    cin >> n;

    vector<int> A(n, 0), B(n, 0);
    Inv temp;

    vector<Inv> Arr(n);

    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        Arr[i] = Inv(start, end, i);
    }

    sort(Arr.begin(), Arr.end(), [&](Inv & i1, Inv & i2) {return (i1.start < i2.start) || ((i1.start == i2.start) && (i1.end > i2.end)); });

    // multiset<Inv, bool(*)(Inv, Inv)>S(end_cmp);


    for (int i = 0; i < n; i++) {
        temp = Arr[i];       
    }

    for (auto b : B) cout << b << blankchar;
    cout << newline;
    for (auto a : A) cout << a << blankchar;
    cout << endl;


    return 0;
}
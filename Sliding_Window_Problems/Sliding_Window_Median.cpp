#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define blankchar ' '
#define newline '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];
    
    if(k == 1){
        while(n--){
            cin >> k;
            cout << k << blankchar;
        }
        cout << newline;
        return 0;
    }

    for (int i = 0; i < n; i++) cin >> arr[i];

    int brr[k];
    for (int i = 0; i < k; i++) {
        brr[i] = arr[i];
    }

    sort(brr, brr + k);

    multiset<int> LS(brr, brr + (k + 1) / 2), RS(brr + (k + 1) / 2, brr + k);


    for (int i = k; i < n; i++) {

        int in = arr[i], out = arr[i - k];
        int median = *LS.rbegin();

        cout << median << blankchar;

        if ( out == median) {
            LS.erase(LS.find(out));
            if(RS.size() == 0 and in <= median){
                LS.insert(in);
            }
            else if (in <= *RS.begin()) {
                LS.insert(in);
            }
            else {
                LS.insert(*RS.begin());
                RS.erase(RS.begin());
                RS.insert(in);
            }
        }
        else if (out <= median and in <= median) {
            LS.erase(LS.find(out));
            LS.insert(in);
        }
        else if (out >= median and in >= median) {
            RS.erase(RS.find(out));
            RS.insert(in);
        }
        else if (out < median and in > median) {
            LS.erase(LS.find(out));
            RS.insert(in);
            LS.insert(*RS.begin());
            RS.erase(RS.begin());
        }
        else if (out > median and in < median) {
            RS.erase(RS.find(out));
            LS.insert(in);
            RS.insert(*LS.rbegin());
            auto it = LS.end();
            it --;
            LS.erase(it);
        }

    }

    cout << *LS.rbegin() << blankchar << endl;

    return 0;

}

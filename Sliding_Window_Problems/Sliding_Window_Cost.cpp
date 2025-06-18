#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

#define blankchar ' '
#define newline '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];

    if (k == 1) {
        while (n--) {
            cin >> k;
            cout << 0 << blankchar;
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
    long long sum_left = accumulate(LS.begin(), LS.end(), 0LL);
    long long sum_right = accumulate(RS.begin(), RS.end(), 0LL);


    for (int i = k; i < n; i++) {

        int in = arr[i], out = arr[i - k];
        int median = *LS.rbegin();

        // cout << sum_left << "   sum   " << sum_right << endl;
        cout << (LS.size()*median - sum_left) + (sum_right - median * RS.size()) << blankchar;
        // cout << "####################" << endl;
        if ( out == median) {

            LS.erase(LS.find(out));
            sum_left -= out;

            if (RS.size() == 0 and in <= median) {
                LS.insert(in);
                sum_left += in;
            }
            else if (in <= *RS.begin()) {
                LS.insert(in);
                sum_left += in;
            }
            else {

                LS.insert(*RS.begin());
                sum_left += *RS.begin();

                sum_right -= *RS.begin();
                RS.erase(RS.begin());
                
                RS.insert(in);
                sum_right += in;
            }
        }
        else if (out <= median and in <= median) {
            LS.erase(LS.find(out));
            sum_left -= out;
            LS.insert(in);
            sum_left += in;
        }
        else if (out >= median and in >= median) {
            RS.erase(RS.find(out));
            sum_right -= out;
            RS.insert(in);
            sum_right += in;
        }
        else if (out < median and in > median) {
            LS.erase(LS.find(out));
            sum_left -= out;

            RS.insert(in);
            sum_right += in;

            LS.insert(*RS.begin());
            sum_left += *RS.begin();

            sum_right -= *RS.begin();
            RS.erase(RS.begin());
        }
        else if (out > median and in < median) {

            RS.erase(RS.find(out));
            sum_right -= out;

            LS.insert(in);
            sum_left += in;

            RS.insert(*LS.rbegin());
            sum_right += *LS.rbegin();

            auto it = LS.end();
            it --;
            sum_left -= *it;
            LS.erase(it);
        }
    }

    int median = *LS.rbegin();
    cout << (LS.size()*median - sum_left) + (sum_right - median * RS.size()) << blankchar << endl;

    return 0;

}
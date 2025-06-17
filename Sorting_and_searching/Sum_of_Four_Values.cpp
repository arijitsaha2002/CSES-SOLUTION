#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
#define Point pair<long long, long long>
#define ll long long
 
bool isLess(const Point &e1, const Point &e2) { return e1.first < e2.first; }
 
inline void MinSwap(ll &A, ll &B) {
    if (A > B) swap(A, B);
}
 
bool findSum(vector<Point> &A, ll j, ll value, ll &x, ll &y) {
    long i = 0;
    long long sum = A[i].first + A[j].first;
    if (value <= 0 or j < 1) return false;
    while (i < j) {
        if (sum == value) {
            x = A[i].second;
            y = A[j].second;
            return true;
        } else if (sum < value) {
            i++;
            if (i == j) break;
            sum = A[j].first + A[i].first;
        } else {
            j--;
            if (i == j) break;
            sum = A[j].first + A[i].first;
        }
    }
    return false;
}
 
bool sumThree(vector<Point> &A, ll &x_, ll &y_, ll &z_, ll x, int l) {
    for (long i = l; i > -1; i--) {
        if (findSum(A, i - 1, x - A[i].first, x_, y_)) {
            z_ = A[i].second;
            return true;
        }
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    ll index[4];
 
    ll x;
    cin >> n >> x;
    vector<Point> A(n);
 
    for (size_t i = 0; i < A.size(); i++) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(A.begin(), A.end(), isLess);
 
    for (int i = A.size() - 1; i > -1; i--) {
        if (sumThree(A, index[0], index[1], index[2], x - A[i].first, i - 1)) {
            index[3] = A[i].second;
            sort(index, index + 4);
            for (auto a : index) {
                cout << a << " ";
            }
            cout << endl;
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}

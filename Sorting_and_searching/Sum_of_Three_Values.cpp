#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
using namespace std;
 
 
 
bool isLess(pair<long long, long> &e1, pair<long long, long> &e2) {
    return e1.first < e2.first;
}
 
void MinSwap(long &A, long &B) {
    long temp = A;
    A = min(A, B);
    B = max(temp, B);
    return;
}
 
 
bool findSum(vector<pair<long long, long>> &A, long j, long long value, long &x , long &y) {
    long i = 0;
    long long sum = A[i].first + A[j].first;
    if (value <= 0 or j < 1 ) return false;
    while (i < j) {
        if (sum == value) {
            x = A[i].second;
            y = A[j].second;
            return true;
        }
        else if ( sum < value) {
            i ++;
            if (i == j) break;
            sum = A[j].first + A[i].first;
        }
        else {
            j --;
            if (i == j) break;
            sum = A[j].first + A[i].first;
        }
    }
    return false;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    long n, x_, y_;
    long long x;
    cin >> n >> x;
    vector<pair<long long , long>> A(n);
    for (size_t i = 0; i < A.size(); i++) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(std::execution::par,A.begin(), A.end());
 
    for (long i = A.size() - 1; i > -1; i --) {
        if (findSum(A, i - 1, x - A[i].first, x_, y_)) {
            MinSwap(x_, y_);
            MinSwap(x_, A[i].second);
            MinSwap(y_, A[i].second);
            cout << x_ << " " << y_ << " " << A[i].second << endl;
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}

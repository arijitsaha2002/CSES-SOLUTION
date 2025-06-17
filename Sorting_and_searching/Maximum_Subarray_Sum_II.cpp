#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
 
#define Point pair<long, long>
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, a, b;
    cin >> n >> a >> b;
 
    Point arr[n], sum[n];
    cin >> arr[0].first;
 
    arr[0].second = 0;
    sum[0] = arr[0];
 
    for (int i = 1; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        sum[i] = arr[i];
        sum[i].first += sum[i - 1].first;
    }
 
    set<Point, bool (*)(Point, Point)> S([](Point p1, Point p2) {
        return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
    });
 
    long T = sum[a - 1].first;
 
    for (int i = a; i < b; i++) {
        S.insert(sum[i - a]);
        auto P = S.begin();
        T = max(T, sum[i].first - min(0L,P->first));
    }
 
    for (int i = b; i < n; i++) {
        S.insert(sum[i - a]);
        auto P = S.begin();
        T = max(T, sum[i].first - P->first);
        S.erase(sum[i - b]);
    }
 
    cout << T << endl;
 
    return 0;
}

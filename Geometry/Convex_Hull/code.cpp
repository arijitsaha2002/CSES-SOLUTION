#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Point {
public:
    long long first, second, index;    
};

void PrintPoint(Point p){
    cout << p.first << " -- " << p.second << endl;
}

long long Distance(Point &P1, Point &P2){
    return (P1.first-P2.first)*(P1.first-P2.first) + (P1.second - P2.second)*(P1.second - P2.second);
}

int main() {
    size_t n;
    cin >> n;
    vector<Point> P(n);
    
    for(size_t i = 0; i < n; i++){ 
        cin >> P[i].first >> P[i].second; 
        P[i].index = i;
    }

    size_t lowestPoint = min_element(P.begin(), P.end(), [](Point & P1, Point & P2) { return P1.second < P2.second;}) - P.begin();

    Point p = P[lowestPoint];
    swap(P[n - 1], P[lowestPoint]);

    // PrintPoint(p);

    sort(P.begin(), P.end() - 1, [&p](Point & P1, Point & P2) {
        long cp = (P1.first - p.first)*(P2.second - p.second) - (P2.first - p.first)*(P1.second - p.second);
        if(cp == 0){
            return Distance(P1,p) > Distance(P2,p);
        }
        return  cp > 0;
    });

    size_t i = -1;
    long cp;
    do{
        i ++;
        // cout << i << endl;
        cp = (P[i].first - p.first)*(P[i+1].second - p.second) - (P[i+1].first - p.first)*(P[i].second - p.second);
    }while(cp == 0);

    // cout << "before reverse" << endl;

    // for(auto p:P){
    //     PrintPoint(p);
    // }

    // cout << i <<endl;
    reverse(P.begin(), P.begin()+i+1);

    // cout << "after reverse" << endl;

    // for(auto p:P){
    //     PrintPoint(p);
    // }

    stack<Point> S;
    S.push(p);
    Point origin = P[0];

    for(size_t i = 1; i < n; i++){
        Point B = S.top(), C = P[i];
        B.first -= origin.first;
        B.second -= origin.second;
        C.first -= origin.first;
        C.second -= origin.second;

        if(C.first*B.second - B.first*C.second >= 0){
            S.push(origin);
            origin = P[i];
        }else{
            origin = P[i];
        }

    }

    cout << S.size() << endl;

    vector<Point> A(S.size());
    i = 0;

    while(!S.empty()){
        A[i] = S.top();
        i ++;        
        S.pop();
    }

    sort(A.begin(), A.end(), [](Point &p1, Point &p2){ return p1.index < p2.index; });

    for(auto a : A){
        cout << a.first << " " << a.second << "\n";
    }


    return 0;
}

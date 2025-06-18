#include <algorithm>
#include<iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define newline '\n'
#define pii pair<int, int>

int main(){
    long n, x;
    cin >> n >> x;
    vector<long> dp(x+1, x+10);
    long coins[n];
    for(auto &c:coins) cin >> c;
    
    dp[0] = 0;
    for(size_t i = 0; i < dp.size(); i++){
        for(auto c:coins){
            if(i + c < dp.size()){
                dp[i + c] = min(dp[i + c], dp[i] + 1);
            }
        }
    }
    cout << (dp[x] != x+10? dp[x]:-1) << endl;
    return 0;
}

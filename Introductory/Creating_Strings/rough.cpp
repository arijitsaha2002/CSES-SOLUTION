#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;
 
#define ll long long
#define fori(i, a, n) for (int i = a; i < n; i++)
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
 
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int,int>>> vvpi;
 
vector<int> func(int n) {
    if(n == 1) {
        return {0,1};
    }
    vector<int> temp = func(n-1);
    for(int i=temp.size()-1;i>=0;i--) {
        temp.push_back(temp[i] | (1<<n-1));
    }
    return temp;
}
 
void solve(){
    int n;
    cin>>n;
    vector<int> a = func(n);
    for(int i=0;i<a.size();i++) {
        int x = n;
        bitset<16> ans(a[i]);
        cout<<ans.to_string().substr(16-n)<<"\n";
    }
}
int main() {
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
#define INPUT(N, arr) for (int i = 0; i < N; cin >> arr[i], i++)
#define newline '\n'
#define FOR(i, N) for (int i = 0; i < N; i++)
#define blankchar ' '
#define Point pair<int, int>
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	multiset<int> Movie;
	
	Point arr[n];
	FOR(i, n){
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n, [](Point p1, Point p2){ return (p1.second < p2.second) || ((p1.second == p2.second) && (p1.first > p2.first));});

	long r = 1;

	Movie.insert(arr[0].second);
	int i = 1;
	for(; i < n; i ++){
		auto it = Movie.upper_bound(arr[i].first);
		if(it == Movie.begin()){
			if(Movie.size() < k){
				Movie.insert(arr[i].second);
				r ++;
			}
		}else{
			it --;
			Movie.erase(it);
			Movie.insert(arr[i].second);
			r ++;
		}
	}
	
	cout << r << endl;
	return 0;
}
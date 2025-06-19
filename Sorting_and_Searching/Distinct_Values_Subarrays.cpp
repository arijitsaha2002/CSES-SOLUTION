#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

int main() {
	int n;
	map<int, vector<int>> positions;
	map<int, int> used;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i ++) {
		cin >> arr[i];
		positions[arr[i]].push_back(i);
		used[arr[i]] = 0;
	}

	for(auto &p: positions) {
		p.second.push_back(n);
	}
	
	set<int> stack;
	stack.insert(n);
	long s = 0, i = 0, result = 0;
	while(s < n) {
		for(; i < *stack.begin(); i ++) {
			int next_pos = positions[arr[i]][used[arr[i]]+1];
			stack.insert(next_pos);
		}
		int l = positions[arr[s]][used[arr[s]]+1];
		if (l != n) stack.erase(l);
		used[arr[s]] ++;
		result += (i - s);
		s ++;
	}
	cout << result << endl;
	return 0;
}	

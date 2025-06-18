#include <iostream>
#include <set>
using namespace std;

int counts[26];
int last_char = -1;
multiset<int, greater<int>> counts_set;

string s, answer;

void replace_count(int o, int n, string s) {
	auto c = counts_set.find(o);
	counts_set.erase(c);
	counts_set.insert(n);
}	

bool is_possible(int current) {
	int total = s.size() - answer.size();
	replace_count(counts[current],counts[current] - 1, "1");
	int max_size = *counts_set.begin();
	replace_count(counts[current] - 1,counts[current], "2");
	return (2*max_size <= total);
}

int get_next_char() {
	for(int i = 0 ; i < 26; i ++) {
		if(counts[i] > 0 and i != last_char and is_possible(i)) {
			replace_count(counts[i],counts[i] - 1, "3");
			counts[i] --;
			last_char = i;
			return i;	
		}
	}
	return -1;
}	

signed main() {
	cin >> s;
	for(char c : s) counts[c - 'A']++;
	for(int c: counts) counts_set.insert(c);
	for(size_t i = 0; i < s.size(); i ++) {
		int l = get_next_char();
		if (l == -1) {
			cout << -1 << endl;
			return 0;
		}
		answer.push_back(l + 'A');
	}
	cout << answer << endl;
	return 0;
}	

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long  tickets, customer;
	cin >> tickets >> customer;

	multiset<long long int> T;
	vector<long long int> C(customer);
	long long int temp;

	for (long long  i = 0; i < tickets; i++) {
		cin >> temp;
		T.insert(temp);
	}
	for (long long  i = 0; i < customer; i++) {
		cin >> C[i];
	}

	for (auto c : C) {

		auto  index = T.upper_bound(c);

		if (index == T.begin()) {
			cout << -1 << endl;
		}
		else {
			index --;
			cout << *index << endl;
			T.erase(index);
		}

	}

	return 0;

}

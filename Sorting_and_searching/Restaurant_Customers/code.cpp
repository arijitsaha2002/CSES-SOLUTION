#include <iostream>
#include <set>
using namespace std;

class C {
public:
	long entry, exit;
};

struct compare {
	bool operator()(const C &lhs, const C &rhs) const {
		return lhs.entry < rhs.entry;
	}
};



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	multiset<C, compare> c;
	C temp;

	while (m--) {
		cin >> temp.entry >> temp.exit;
		c.insert(temp);
	}

	int r = 0;

	for (; c.size() != 0; r++) {

		auto a = c.begin(), n = c.begin();

		do {
			temp = *a;
			temp.entry = temp.exit;
			n = c.upper_bound(temp);
			c.erase(a);
			a = n;

		} while (a != c.end());


	}

	cout << r << endl;

	return 0;
}

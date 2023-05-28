#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Movie {
public:
	long start, end;
};



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long movies;
	cin >> movies;
	vector<Movie> M(movies);

	for (long i = 0 ; i < movies; i++) {
		cin >> M[i].start >> M[i].end;
	}

	sort(M.begin(), M.end(), [&](Movie & m1, Movie & m2) {return m1.end < m2.end;});

	long r = 1, ending = M[0].end;

	for (long i = 1; i < movies; i++) {
		if (M[i].start >= ending) {
			ending = M[i].end;
			r ++;
		}
	}

	cout << r << endl;

	return 0;
}

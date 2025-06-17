#include <iostream>
using namespace std;

#define newline '\n'

bool is_possible(int n, int a, int b) {
	if (a+b > n) return false;
	else if (a == 0 and b == 0) return true;
	else if (a == 0 or b == 0) return false;
	else return true;
}	

void solve() {
	int n, a, b;
	cin >> n  >> a >> b;
	int index = n - 1;
	int a_coins[n], b_coins[n];
	if (is_possible(n, a, b)) {
		cout << "YES" << newline;
		int i;
		for(i = n; i > a + b; i --) {
			a_coins[index] = i;
			b_coins[index] = i;
			index --;
		}

		for(; index > -1 ; index --) {
			a_coins[index] = (a+b) - (a + a + b - index - 1) % (a+b);
			b_coins[index] = index + 1;
		}

		for(auto c: a_coins) cout << c << " ";
		cout << newline;
		for(auto c: b_coins) cout << c << " ";
		cout << newline;
		
	} else {
		cout << "NO" << newline;
	}
}	

int main() {
	int t;
	cin >> t;
	while(t--) solve();
}	

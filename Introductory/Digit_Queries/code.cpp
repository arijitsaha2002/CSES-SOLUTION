#include <iostream>
using namespace std;

char GetValue(long n) {
	if( n < 10) return to_string(n)[0];
	int length = 1;
	long long p = 10 , i = 0, temp;

	while (n >= length) {
		temp = n;
		n -= (p - i) * length;
		i = p;
		length ++;
		p *= 10;
	}
	i /= 10;
	length --;

	i += (temp / length);
	string s = to_string(i);
	return s[temp % length];
}

int main() {

	int testCase;
	cin >> testCase;
	long long n;
	while ( testCase--) {
		cin >> n;
		cout << GetValue(n) << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;
 
char GetValue(long n) {
	int length = 1;
	long long p = 10 , i = 0;
 
	while (n - (p - i) * length >= length) {
		n -= (p - i) * length;
		i = p;
		length ++;
		p *= 10;
	}
 
	i += (n / length);
	string s = to_string(i);
	return s[n % length];
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

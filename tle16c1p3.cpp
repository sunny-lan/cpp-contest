#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ll a = 1, b = 1, c = 1, d = 1;
	string s; getline(cin, s);
	int n = s.length();
	ll mult = 1;
	ll ah = 0, ac = 0, ao = 0;
	for (int i = n - 1; i >= 0; i--) {
		char c = s[i];
		if (isdigit(c)) {
			mult = c - '0';
		}
		else {
			if (c == 'H')
				ah += mult;
			if (c == 'C')
				ac += mult;
			if (c == 'O')
				ao += mult;

			mult = 1;
		}
	}

	//balance h
	if (a*ah % 2 != 0)
		a *= 2;
	d = a*ah / 2;

	//balance c
	c = a*ac;

	//balance o
	ll lo = a*ao;
	ll ro = c * 2 + d;
	if (lo > ro)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	if ((ro - lo) % 2 != 0)
		a *= 2, c *= 2, d *= 2;
	lo = a*ao;
	ro = c * 2 + d;
	b = (ro - lo) / 2;

	ll cm = gcd(a, gcd(b, gcd(c, d)));
	a /= cm, b /= cm, c /= cm, d /= cm;

	if (a == 0 || b == 0 || c == 0 || d == 0) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << a << s << " + " << b << "O2 -> " << c << "CO2 + " << d << "H2O" << endl;
	cin >> b;
}
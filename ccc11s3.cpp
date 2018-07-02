#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int testcase = 0; testcase < t; testcase++) {
		ll m, x, y; scanf("%lld %lld %lld", &m, &x, &y);
		ll mult = 1;
		ll res = 0;
		for (int i = 0; i < m; i++) {
			ll pos = x % 5;
			ll v;
			if (pos == 0)
				v = 0;
			if (pos == 1)
				v = 1;
			if (pos == 2)
				v = 2;
			if (pos == 3)
				v = 1;
			if (pos == 4)
				v = 0;
			res += mult*v;
			if (v == 0)res = 0;
			mult *= 5;
			x /= 5;
		}
		if (res > y)
			printf("crystal\n");
		else
			printf("empty\n");
	}
	cin >> t;
}
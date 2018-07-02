#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000011

ll a[MAXN];

int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	for (int i = 0; i < k; i++)scanf("%lld", &a[i]), a[i]--;
	ll res = 0;
	for (int i = 0; i < k; i++) {
		if (i + 2 >= k)break;
		ll prv;
		if (i == 0)
			prv = 0;
		else
			prv = a[i-1]+1;

		ll m1 = n - a[i + 2];
		ll m2 = a[i] - prv + 1;
		res += m1*m2;
	}
	printf("%lld\n", res);
	cin >> n;
}
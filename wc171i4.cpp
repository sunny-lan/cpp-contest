#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXM 100000
ll d[MAXM];

int main() {
	ll n, p, b, c;
	scan(n); scan(p); scan(b); scan(c);
	ll m, w; scan(m); scan(w);
	ll k = 0, l = 0;
	for (ll i = 0; i < m; i++) {
		scan(d[i]);
		d[i]--;
		k += d[i] * w;
		l += d[i] * b;
	}
	if (w <= b) {
		printf("%lld\n", k);
	}
	else {
		if (c >= m)
			printf("%lld\n", l);
		else {
			sort(d, d + m);
			ll nt = 0;
			ll ccap = 0;
			ll tot = 0;
			for (ll i = m - 1; i >= 0; i--) {
				if (ccap == c) {
					ccap = 0;
					nt += p;
				}
				ll walkt = d[i] * w;
				ll bust = d[i] * b + nt;
				if (bust < walkt) {
					tot += bust;
					ccap++;
				}
				else {
					tot += walkt;
				}
			}
			printf("%lld\n", tot);
		}
	}
	cin >> n;
}
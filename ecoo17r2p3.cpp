#ifdef DMOJ

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
#include <set>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int n, m;
pii r[MAXN];

ll f(ll x) {
	ll tot = 0;
	ll round = m*(x + 1);
	for (int i = 0; i < n; i++)
		if (r[i].first < round)
			tot += (round - r[i].first + m - 1) / m;
	return tot;
}

inline void _main() {
	ll k; scan(n); scan(m); scan(k);
	k--;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		scan(r[i].first);
		r[i].second = i + 1;
		maxi = max(maxi, r[i].first);
	}
	for (int i = 0; i < n; i++)
		r[i].first = maxi - r[i].first;

	ll lo = 0;
	ll hi = k;

	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		ll res = f(mid);
		if (res <= k)
			lo = mid + 1;
		else
			hi = mid;
	}

	ll res = f(lo - 1);

	for (int i = 0; i < n; i++)
		if (r[i].first < (lo + 1)*m)
			r[i].first %= m;
		else
			r[i].first = INT_MAX;

	sort(r, r + n);

	printf("%d\n", r[k - res].second);
}

int main() {
	for (int i = 0; i < 10; i++)_main();
}
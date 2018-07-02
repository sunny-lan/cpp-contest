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

#define MAXN 32
ll c[MAXN];

int main() {
	memset(c, 0x3f, sizeof c);
	int n; ll l; scan(n); scan(l);
	for (int i = 0; i < n; i++)
		scan(c[i]);
	for (int i = 0; i < MAXN - 1; i++)
		c[i + 1] = min(c[i + 1], c[i] * 2);
	for (int i = MAXN - 1; i > 0; i--)
		c[i - 1] = min(c[i], c[i - 1]);
	ll ans = 0;
	for (int i = 0; i < MAXN; i++)
		if ((l >> i) & 1)
			ans += c[i];
	for (int j = 0; j < MAXN; j++)if (!((l>>j)&1)) {
		ll res = 0;
		ll tmp = l & ~((1ll << j) - 1ll);
		res += c[j];
		for (int i = 0; i < MAXN; i++)
			if ((tmp >> i) & 1)
				res += c[i];
		ans = min(ans, res);
	}
	printf("%I64d\n", ans);
	cin >> n;
}
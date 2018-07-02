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

#define MAXN 100000

ll hi[MAXN];

int main() {
	int n, m, k; scan(n); scan(m); scan(k);
	ll mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		ll h; scan(h);
		mini = min(mini, h);
		hi[i] = h;
	}
	if (k == 1)
	{
		for(int i=0;i<n;i++)
			if (hi[i] == mini) {
				for (int j = i; j < min(n,i + m); j++) {
					hi[j]++;
				}
				break;
			}
		ll mini = INT_MAX;

		for (int i = 0; i<n; i++)
			mini = min(mini, hi[i]);
		printf("%lld\n", mini);

		return 0;
	}
	else {
		sort(hi, hi + n);
		ll currlvl = 0;
		int curcnt = 0;
		for (int i = 0; i < n; i++) {
			if (hi[i] == currlvl) {
				curcnt++;
			}
			else {
				if (curcnt*(hi[i] - currlvl) > k)
					break;
				k -= curcnt*(hi[i] - currlvl);
				curcnt++;
				currlvl = hi[i];
			}
		}
		currlvl += k / curcnt;
		printf("%lld\n", currlvl);
	}
}
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

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100010

ll pre[MAXN];
unordered_map<ll, ll> cust;

int main() {
	int n, m; scan(n); scan(m);

	for (int i = 0; i < n; i++) {
		ll c; scan(c);
		pre[i + 1] += pre[i]+c;
		pre[i + 1] %= m;
		cust[pre[i]]++;
	}
	cust[pre[n]]++;

	ll tot = 0;
	for (auto cnt : cust) {
		//if (cnt.second > 1)
			tot += cnt.second*(cnt.second - 1)/2;
	}

	printf("%lld\n", tot);
}
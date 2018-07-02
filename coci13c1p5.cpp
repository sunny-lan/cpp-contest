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

#define MAXK 2000009

ll cnt[MAXK+1];

int main() {
	memset(cnt, 0, sizeof(cnt));

	ll n; scan(n);
	for (ll i = 0; i < n; i++) {
		int k; scan(k);
		cnt[k]++;
	}

	ll maxi = 0;
	for (ll i = 1; i <= MAXK; i++) {
		ll tmp = 0;
		for (ll j = i; j <= MAXK; j += i)
			tmp += cnt[j];
		if(tmp>1)
		maxi = max(maxi, tmp*i);
	}

	printf("%lld\n", maxi);
	cin >> n;
}
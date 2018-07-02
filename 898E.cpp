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
#include <set>
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

#define MAXA 1100000000ll
#define MAXN 200010ll

ll dst[MAXN];

int main() {
	set<ll> pft;
	for (ll i = 0; i*i <= MAXA; i++)
		pft.insert(i*i);
	ll n; scan(n);
	ll cnt = 0;
	ll zeroes = 0;
	for (ll i = 0; i < n; i++) {
		ll v; scan(v);
		if (v == 0) zeroes++;
		if (pft.find(v) != pft.end()) {
			cnt++;
			dst[i] = 0;
			continue;
		}
		auto nxt = pft.lower_bound(v);
		dst[i] = *nxt - v;
		dst[i] = min(dst[i], v - *prev(nxt));
		dst[i] = abs(dst[i]);
		if (dst[i] == 0)while (true)printf("1");
	}
	ll ans = 0;
	if (cnt == n / 2) {}
	else if (cnt > n / 2) {
		ll non = cnt - zeroes;//sqares that!=0
		ll need = cnt - n / 2;//amount of squares to be removed
		ans += min(non, need);//first remove all squares !=0 by adding 1
		need -= min(non, need);
		if (need > zeroes)while (true)need ^= ans;
		ans += need * 2;//then use all squares=0	
	}
	else {
		sort(dst, dst + n);
		for (ll i = 0; i < n / 2; i++)
			ans += dst[i];
	}
	printf("%I64d", ans);
	cin >> n;
}
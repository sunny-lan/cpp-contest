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

int main() {
	ll x; scan(x);
	ll h, m; scan(h); scan(m);
	ll s = h * 60 + m;
	int cnt = 0;
	while (true) {
		ll hx = s / 60;
		ll mx = s % 60;
		if (hx % 10 == 7) break;
		if (mx % 10 == 7)break;
		s -= x;
		if (s < 0)
			s += 24 * 60 ;
		cnt++;
		//kust
	}
	printf("%d", cnt);
}
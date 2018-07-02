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
	ll s; scan(s);
	ll n, p; scan(n); scan(p);
	ll pas = n;
	ll maxi = pas;
	for (ll i = 1; i < s; i++) {
		scan(n); scan(p);
		ll sub = pas*p / 100;
		pas -= sub;
		pas += n;
		maxi = max(maxi, pas);
	}
	
	printf("%lld", (maxi + 131) / 131-(maxi+250)/251);
	cin >> maxi;
}
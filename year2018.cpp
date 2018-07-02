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
	ll h, m, s; scan(h); scan(m); scan(s);
	ll tot = h * 3600 + m * 60 + s;
	ll nxtmidnight = (tot / 86400) * 86400 + 86400;
	tot = nxtmidnight - tot;
	ll oh = tot / 3600;
	tot -= oh * 3600;
	ll om = tot / 60;
	tot -= om * 60;
	ll os = tot;
	oh %= 12;
	printf("%02lld:%02lld:%02lld\n", oh, om, os);
	cin >> h;
}
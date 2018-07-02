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
	ll x, y; scan(x); scan(y);
	if (y == 0) {
		printf("No");
		return 0;
	}
	ll origcpy = y - 1;
	x -= origcpy;
	if (x < 0)printf("No");
	else {
		if (x > 0 && origcpy <= 0)printf("No");
		else {
			if (x % 2 == 0)printf("Yes");
			else printf("No");
		}
	}
	cin >> x;
}
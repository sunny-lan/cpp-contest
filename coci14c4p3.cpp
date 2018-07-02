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


int main() {
	int n; scan(n);
	int maxi = 0;
	ll t = 0;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		int x; scan(x);
		t += x;
		if (x > maxi) {
			s += maxi;
			maxi = x;
		}
		else
			s += x;
	}
	if (maxi > s)
		t = maxi * 2;
	printf("%lld\n", t);
}
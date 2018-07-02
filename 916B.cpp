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


int popcnt(ull w) {
	w -= (w >> 1) & 0x5555555555555555ULL;
	w = (w & 0x3333333333333333ULL) + ((w >> 2) & 0x3333333333333333ULL);
	w = (w + (w >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
	return int((w * 0x0101010101010101ULL) >> 56);
}


int main() {
	ll n, k; scan(n); scan(k);
	int cnt = popcnt((ull)n);
	if (cnt > k) {
		printf("No");
		return 0;
	}
	for (int i = 63; i >= 0; i--) {
		if ((n >> i) & 1) {
			int left = k-(cnt - 1);
			ll x = 1;
			int cnt = 0;
			int ti = i;
			while ((x << 1) <= left) {
				cnt++;
				ti--;
				x <<= 1;
			}
			printf("Yes\n");
			for (int j = 0; j < x; j++)
				printf("%d ", ti);
			for (int j = i - 1; j >= 0; j--)
				if ((n >> j) & 1)
					printf("%d ", j);
			break;
		}
	}
	cin >> n;
}
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

#define MAXN 1000

ull nums[MAXN];

int population_count64(ull w) {
	w -= (w >> 1) & 0x5555555555555555ULL;
	w = (w & 0x3333333333333333ULL) + ((w >> 2) & 0x3333333333333333ULL);
	w = (w + (w >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
	return int((w * 0x0101010101010101ULL) >> 56);
}

int main() {
	memset(nums, 0, sizeof nums);

	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++) {
		int s; scan(s);
		for (int j = 0; j < s; j++) {
			int k; scanf("%d", &k);
			k += 30;
			nums[i] |= 1ull << k;
		}
	}

	for (int i = 0; i < q; i++) {
		ull res = 0;
		int m; scan(m);
		for (int j = 0; j < m; j++) {
			int id; scan(id);
			id--;
			res ^= nums[id];
		}
		printf("%d", population_count64(res));
		for (int j = -30; j <= 30; j++) {
			if ((res >> (j + 30)) & 1ull)
				printf(" %d", j);
		}
		printf("\n");
	}
}
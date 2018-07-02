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

#define MAXN 210000
#define MAXL 22

ll sparse[MAXL][MAXN];

ll *pre = sparse[0];

bool pred(ll a, ll b) {
	return a > b;
}

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

inline ll query(int i, int j) {
	int bsI = count_bits(j - i);
	ll a = sparse[bsI][i],
		b = sparse[bsI][j - (1 << bsI)];
	return pred(a, b) ? a : b;
}

inline void construct(int n) {
	int bs = 1, bsI = 0;
	bs <<= 1, bsI++;
	while (bs < n) {
		for (int i = 0; i + bs <= n; i++) {
			ll a = sparse[bsI - 1][i], b = sparse[bsI - 1][i + (bs >> 1)];
			sparse[bsI][i] = pred(a, b) ? a : b;
		}
		bs <<= 1, bsI++;
	}
}

ll val[MAXN];

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &val[i]);
		val[i + n] = val[i];
	}
	for (int i = 0; i < n * 2; i++) {
		pre[i + 1] += val[i];
		pre[i + 1] += pre[i];
	}
	construct(n * 2 + 2);
	ll maxi = 0;
	for (int i = 0; i < n; i++) {
		ll res = query(i + 1, i + k + 1) - pre[i];
		maxi = max(maxi, res);
	}
	printf("%lld\n", maxi);
}
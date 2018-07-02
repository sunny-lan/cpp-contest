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
#include <set>

#endif // DMOJ
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100001
#define MAXB 17

bool pred(pii a, pii b) {
	int x = (a.second - a.first),
		y = (b.second - b.first);
	if (x == y)
		return a.first < b.first;
	return x > y;
}

pii sparse[MAXB][MAXN * 2];

inline int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

inline pii query(int i, int j) {
	int bsI = count_bits(j - i);
	pii a = sparse[bsI][i],
		b = sparse[bsI][j - (1 << bsI)];
	return pred(a, b) ? a : b;
}

inline void construct(int n) {
	int bs = 1, bsI = 0;
	bs <<= 1, bsI++;
	while (bs < n) {
		for (int i = 0; i + bs <= n; i++) {
			pii a = sparse[bsI - 1][i], b = sparse[bsI - 1][i + (bs >> 1)];
			sparse[bsI][i] = pred(a, b) ? a : b;
		}
		bs <<= 1, bsI++;
	}
}

pii* val = sparse[0];

int arr[MAXN];
multiset<int>::iterator it[MAXN];

bool pred1(pii a, int b) {
	return a.first < b;
}

bool pred2(int a, pii b) {
	return a < b.second;
}

int main() {
	int n, k; scan(n); scan(k);
	for (int i = 0; i < n; i++)
		scan(arr[i]);

	int cnt = 0;
	multiset<int> custs;
	int b = 0;
	for (int a = 0; a < n; a++) {
		while (b < n) {
			int diff;
			if (custs.empty()) diff = 0;
			else diff = abs(max(*custs.rbegin(), arr[b]) - min(*custs.begin(), arr[b]));
			if (diff > k)break;
			it[b] = custs.insert(arr[b]);
			b++;
		}

		if (a < b)
			val[cnt++] = { a,b };

		if (custs.empty())continue;
		custs.erase(it[a]);
	}

	construct(cnt);
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int l, r; scan(l); scan(r);
		l--;
		int innerL = lower_bound(val, val + cnt, l, pred1) - val,
			innerR = upper_bound(val, val + cnt, r, pred2) - val;
		pii best = { n,n };
		if (innerL < innerR) {
			best = query(innerL, innerR);
		}
		if (innerL > 0) {
			if (val[innerL].first > l) innerL--;
			pii touchL = val[innerL];
			touchL.first = l, touchL.second = max(l, min(r, touchL.second));
			if (pred(touchL, best)) best = touchL;
			innerL++;
		}
		if (innerR < cnt - 1) {
			if (val[innerR].second < r) innerR++;
			pii touchR = val[innerR];
			touchR.first = min(r, max(l, touchR.first)), touchR.second = r;
			if (pred(touchR, best)) best = touchR;
			innerR--;
		}
		printf("%d %d\n", best.first + 1, best.second);
	}

	cin >> q;
}
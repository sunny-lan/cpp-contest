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
typedef pair<ll, int> pli;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

//template parameters
#define MAXL 5000
#define NUM pli

typedef pair<int, pair<pii, pii>> block;

#define MAXN 100000

//template begin
NUM *bit[MAXL + 2];
//NOTE: p is inclusive [0,p]
//NOTE: p starts at 0, not 1
void update(int p, int q, NUM v) {
	p++, q++;
	for (int x = p; x < MAXL; x += x&-x)
		for (int y = q; y < MAXL; y += y&-y) {
			if (bit[x] == (NUM*)-1)
				bit[x] = new NUM[MAXL + 2],
				memset(bit[x], -1, (MAXL + 2) * sizeof(int));
			bit[x][y] = max(v, bit[x][y]);
		}
}

NUM query(int p, int q) {
	p++, q++;
	NUM res = { 0,-1 };
	for (int x = p; x > 0; x -= x&-x)
		for (int y = p; y > 0; y -= y&-y) {
			if (bit[x] == (NUM*)-1)
				bit[x] = new NUM[MAXL + 2],
				memset(bit[x], -1, (MAXL + 2) * sizeof(int));
			res = max(res, bit[x][y]);
		}
	return res;
}

block blocks[MAXN];
int src[MAXN];

int main() {
	memset(bit, -1, sizeof bit);
	int n; scan(n);
	for (int i = 0; i < n; i++) {
		int l, w, h, p;
		scan(l); scan(w); scan(h); scan(p);
		blocks[i] = { h,{ { max(l,w),min(w,l) },{ p,i } } };
	}
	sort(blocks, blocks + n);
	for (int i = 0; i < n; i++) {
		int l = blocks[i].second.first.first,
			w = blocks[i].second.first.second,
			idx = blocks[i].second.second.second;
		ll p = blocks[i].second.second.first;
		pli res = query(l, w);
		src[idx] = res.second;
		update(l, w, { res.first + p, idx });
	}
	pli res = query(MAXL, MAXL);
	vector<int> st;
	int tmp = res.second;
	while (tmp != -1) {
		st.push_back(tmp);
		tmp = src[tmp];
	}
	printf("%lld\n%d\n", res.first, (int)st.size());
	for (int i : st)printf("%d ", i + 1);
	printf("\n");
	cin >> n;
}
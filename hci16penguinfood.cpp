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


#define MAXN 1000000

struct O {
	int l = -(1ll << 30), r = -(1ll << 30),
		w = 0, m = -(1ll << 30);
	O() {}
	O(int il, int ir, int iw, int im) {
		l = il, r = ir, w = iw, m = im;
	}
};

O com(O l, O r) {
	O s;
	s.l = max(l.w + r.l, l.l);
	s.r = max(r.w + l.r, r.r);
	s.w = l.w + r.w;
	s.m = max(max(l.r + r.l, s.w), max(l.m, r.m));
	return s;
}


struct seg {
	int l, r;
	O val;
};

O dat[MAXN];
seg tree[MAXN * 3];

void push_up(int i) {
	tree[i].val = com(
		tree[i << 1].val,
		tree[i << 1 | 1].val);
}
void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	if (l + 1 == r) {
		tree[i].val = dat[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int p, O x, int i = 1) {
	if (tree[i].l == p && tree[i].r == p + 1) {
		tree[i].val = x;
		return;
	}
	if (tree[i].r <= p || tree[i].l > p)return;
	update(p, x, i << 1); update(p, x, i << 1 | 1);
	push_up(i);
}

O  query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return O();
	return com(query(l, r, i << 1), query(l, r, i << 1 | 1));
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		dat[i] = O(x, x, x, x);
	}
	build(0, n + 1);
	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int x, y; scanf("%d %d", &x, &y);
		 printf("%d\n",max(0, query(0, n).m));
		 update(x, O(y, y, y, y));
	}
	printf("%d\n", max(0, query(0, n).m));
	cin >> q;
}
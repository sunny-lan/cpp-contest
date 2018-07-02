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

#define MAXN 100010

ll psa[11][MAXN];

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	ll val;
	ll lazy;
	bool isLazy;
};

ll dat[MAXN];
seg tree[MAXN * 3];

int currk;

void push_up(int i) {
	tree[i].val =
		tree[i << 1].val +
		tree[i << 1 | 1].val;
}

void apply(int i, ll lazy) {
	tree[i].val += psa[currk][tree[i].r] - psa[currk][tree[i].l];
	tree[i].lazy += lazy;
	tree[i].isLazy = true;
}

void push_down(int i) {
	if (!tree[i].isLazy) return;
	apply(i << 1, tree[i].lazy);
	apply(i << 1 | 1, tree[i].lazy);

	tree[i].isLazy = false;
	tree[i].lazy = 0;
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

void update(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, i << 1); update(l, r, i << 1 | 1);
	push_up(i);
}

ll query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

#define MOD 1000000007ll

ll mpow(int a, int p) {
	ll res = 1;
	ll curr = a;
	while (p > 0) {
		if (p & 1)
			res *= curr, res %= MOD;
		curr *= curr, curr %= MOD;
		p >>= 1;
	}
	return res;
}

int main() {
	int n, q; scan(n); scan(q);

	for (int i = 0; i <= 10; i++) {
		for (int j = 1; j <= n; j++) {
			psa[i][j] = mpow(j, i);
			psa[i][j] += psa[i][j - 1];
			psa[i][j] %= MOD;
		}
	}

	build(0, n + 1);
	for (int i = 0; i < q; i++) {
		char op; scanf(" %c", &op);
		int l, r; scan(l); scan(r);
		l--;
		if (op == 'U') {
			scan(currk);
			update(l, r);
		}
		else {

		}
	}

	cin >> q;
}
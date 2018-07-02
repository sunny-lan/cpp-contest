#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct seg {
	int l, r, vl = 0, lz = 0;
};

seg tree[3 * N];

void apply(int n, int v) {
	tree[n].vl += v;
	tree[n].lz += v;
}

void psh(int n) {
	apply(n << 1, tree[n].lz);
	apply(n << 1 | 1, tree[n].lz);
	tree[n].lz = 0;
}

void build(int l, int r, int n = 1) {
	tree[n].l = l, tree[n].r = r;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, n << 1);
	build(mid + 1, r, n << 1 | 1);
}

void update(int l, int r, int v, int n = 1) {
	if(tree[n].l > r || tree[n].r < l)
		return;
	if(tree[n].l >= l && tree[n].r <= r) {
		apply(n, v);
		return;
	}
	psh(n);
	update(l, r, v, n << 1);
	update(l, r, v, n << 1 | 1);
	tree[n].vl = max(tree[n << 1].vl, tree[n << 1 | 1].vl);
}

int query(int l, int r, int n = 1) {
	if(tree[n].l > r || tree[n].r < l)
		return 0;
	if(tree[n].l >= l && tree[n].r <= r)
		return tree[n].vl;
	psh(n);
	return max(query(l, r, n << 1), query(l, r, n << 1 | 1));
}

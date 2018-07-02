#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

struct val {
	int mini = -1, gd = 0, gc = 0;
};

struct seg {
	int l, r;
	val v;
};

#define MAXN 100001

seg tree[MAXN * 3];
int dat[MAXN];

val combine(val a, val b) {
	if (a.mini == -1)return b;
	if (b.mini == -1)return a;
	val res;
	res.mini = min(a.mini, b.mini);
		res.gd = gcd(a.gd, b.gd);
		if (a.gd == res.gd)
			res.gc += a.gc;
		if (b.gd == res.gd)
			res.gc += b.gc;
	return res;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l, tree[i].r = r;
	if (r - l <= 1)
	{
		tree[i].v.mini = tree[i].v.gd = dat[l];
		tree[i].v.gc = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	tree[i].v = combine(tree[i << 1].v, tree[i << 1 | 1].v);
}

void update(int x, int v, int i = 1) {
	if (x < tree[i].l || x >= tree[i].r)return;
	if (tree[i].r - tree[i].l <= 1)
	{
		tree[i].v.mini = tree[i].v.gd = v;
		tree[i].v.gc = 1;
		return;
	}
	update(x, v, i << 1); update(x, v, i << 1 | 1);
	tree[i].v = combine(tree[i << 1].v, tree[i << 1 | 1].v);
}

val query(int l, int r, int i = 1) {
	if (r <= tree[i].l || l >= tree[i].r) {
		val def;
		def.mini = -1;
		return def;
	}
	if (tree[i].l >= l && tree[i].r <= r)return tree[i].v;
	return combine(query(l, r, i << 1), query(l, r, i << 1 | 1));
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &dat[i]);

	build(0, n);

	for (int i = 0; i < m; i++) {
		char op; int a, b; scanf(" %c %d %d", &op, &a, &b);
		a--;
		if (op == 'C') {
			update(a, b);
		}
		else if (op == 'M') {
			printf("%d\n", query(a, b).mini);
		}
		else if (op == 'G') {
			printf("%d\n", query(a, b).gd);
		}
		else if (op == 'Q') {
			printf("%d\n", query(a, b).gc);
		}
	}
	cin >> n;
}
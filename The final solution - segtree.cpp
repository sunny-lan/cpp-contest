#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

#define MAXN 200001

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	ll val;
	ll lazy;
	bool isLazy;
};

ll dat[MAXN];
seg tree[MAXN * 3];

void push_up(int i) {
	tree[i].val =
		tree[i << 1].val +
		tree[i << 1 | 1].val;
}

void apply(int i, ll lazy) {
	tree[i].val += lazy * (tree[i].r - tree[i].l );
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
	if (l+1 == r ) {
		tree[i].val = dat[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int l, int r, ll x, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, i << 1); update(l, r, x, i << 1 | 1);
	push_up(i);
}

ll query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

int main() {
	int n, q; scan(n); scan(q);
	for (int i = 0; i < n; i++)
		scan(dat[i]);

	build(0, n - 1);

	for (int i = 0; i < q; i++) {
		int op, l, r; scan(op); scan(l); scan(r);
		l--; r--;
		if (op == 1)
			printf("%lld\n", query(l, r));
		else
		{
			int x; scan(x);
			update(l, r, x);
		}
	}
	cin >> n;
}
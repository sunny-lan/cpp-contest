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
	tree[i].val = max(
		tree[i << 1].val ,
		tree[i << 1 | 1].val);
}

void apply(int i, ll lazy) {
	tree[i].val += lazy ;
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
	return max(query(l, r, i << 1) , query(l, r, i << 1 | 1));
}

int main() {
	int nx;
	scan(nx); int k, q; scan(k); scan(q);
	build(0, nx);
	for (int i = 0; i < q; i++) {
		int op; scan(op);
		if (op == 0) {
			int p; ll v; scan(p); scan(v);
			p++;
			int l = max(1, p - k+1);
			p++;
			//cout << "[" << l << ", " << p << ")" << endl;
			update(l, p, v);
		}
		else {
			int l, r; scan(l); scan(r);
			if (l > r) { printf("0\n"); continue; }
			l++, r++;
			printf("%lld\n", query(l, r + 1));
		}
		/*cout << "Val:  ";
		for (int i = 1; i <= nx; i++)
			cout << query(i, i + 1) << " ";
		cout << endl;*/
	}
	cin >> nx;
}
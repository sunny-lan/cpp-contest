#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 1000001

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
	tree[i].val += lazy * (tree[i].r - tree[i].l);
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
	return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

bool prime[MAXN];

int main() {
	ll n, t; scanf("%lld %lld", &n, &t);
	for (ll i = 2; i <=max(n,t); i++)
	{
		for (ll j = 2; j*j <= i; j++)
			if (i%j == 0)
				goto outer;
		prime[i] = true;
	outer:continue;
	}

	for (int i = 0; i < n; i++) {
		 scanf("%lld", &dat[i]);
	}

	build(0, MAXN-1);

	ll mini = LLONG_MAX;
	for (ll i = 1; i <= t; i++) {
		ll a, b, k; scanf("%lld %lld %lld", &a, &b, &k);
		a--;
		if (prime[i]) {
			mini = min(mini, i*(query(a,b) + k));
		}
		else {
			update(a,b, k);
		}
	}

	printf("%lld\n", mini);
	
	cin >> n;
}
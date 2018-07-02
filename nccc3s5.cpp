#ifndef _MSC_VER

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

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAXP 2000010

#define NOLAZY 0
#define LAZYPROP 1
#define LAZYCLR 2

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	ll cones = 0;
	ll price = 0;
	ll lazy = 0; //num of cones to be added
	int lazyMode = NOLAZY;
};

ll dat[MAXP];
seg tree[MAXP * 3];

void push_up(int i) {
	tree[i].cones =
		tree[i << 1].cones +
		tree[i << 1 | 1].cones;
	tree[i].price =
		tree[i << 1].price +
		tree[i << 1 | 1].price;
}

void apply(int i, ll lazy, bool clear) {
	if (clear) {
		tree[i].cones = 0;
		tree[i].price = 0;
		tree[i].lazy = 0;
		tree[i].lazyMode = LAZYCLR;
		return;
	}
	tree[i].cones += lazy * (tree[i].r - tree[i].l);
	tree[i].price -= lazy * (tree[i].l - tree[i].r) * (tree[i].l + tree[i].r - 1) / 2;
	tree[i].lazy += lazy;
	tree[i].lazyMode = LAZYPROP;
}

void push_down(int i) {
	if (tree[i].lazyMode == NOLAZY) return;
	if (tree[i].lazyMode == LAZYPROP) {
		apply(i << 1, tree[i].lazy, false);
		apply(i << 1 | 1, tree[i].lazy, false);
	}
	else {
		apply(i << 1, 0, true);
		apply(i << 1 | 1, 0, true);
	}
	tree[i].lazyMode = NOLAZY;
	tree[i].lazy = 0;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	if (l + 1 == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int l, int r, ll x, bool clear, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x, clear);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, clear, i << 1); update(l, r, x, clear, i << 1 | 1);
	push_up(i);
}

pll query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return{ tree[i].cones, tree[i].price };
	if (tree[i].r <= l || tree[i].l >= r) return{ 0,0 };
	push_down(i);
	pll resl = query(l, r, i << 1), resr = query(l, r, i << 1 | 1);
	return{ resl.first + resr.first, resl.second + resr.second };
}

//lower_bound
//finds the first element that is >= than val
//lo=0, hi=n
//while lo<hi:
//  mid=(lo+hi)/2
//  if f(mid)>=val:
//     hi=mid
//  else:
//     lo=mid+1

//upper_bound
//finds the first element that is > than val
//lo=0, hi=n
//while lo<hi:
//  mid=(lo+hi)/2
//  if f(mid)>x:
//     hi=mid
//  else:
//     lo=mid+1



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	build(0, MAXP - 1);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string op; cin >> op;
		if (op == "ADD") {
			ll k; int p; cin >> k >> p;
			update(p, p + 1, k, false);
		}
		else if (op == "ADDRANGE") {
			int a, b; cin >> a >> b;
			update(a, b + 1, 1, false);
		}
		else if (op == "BUYAMT") {
			ll q; cin >> q;
			ll lo = 0, hi = MAXP - 4;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				pll res = query(0, mid + 1);
				if (res.second >= q)
					hi = mid;
				else
					lo = mid + 1;
			}
			//lo = max(0, lo - 1);
			pll base = query(0, lo);
			q -= base.second;
			printf("%lld\n", base.first + q / lo);
			update(0, lo, 0, true);
			update(lo, lo + 1, -q / lo, false);
		}
		else if (op == "BUYLOW") {

		}
		else if (op == "NUMCONES") {
			printf("%lld\n", query(0, MAXP - 4).first);
		}
		else if (op == "TOTALCOST") {
			printf("%lld\n", query(0, MAXP - 4).second);
		}
		/*for (int j = 0; j < 15; j++) {
			printf("%lld ", query(j, j + 1).first);
		}
		printf("\n");
		for (int j = 0; j < 15; j++) {
			printf("%lld ", query(0, j).second);
		}
		printf("\n");*/
	}
	cin >> n;
}
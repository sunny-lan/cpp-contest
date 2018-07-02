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

#define MAXN 250001

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	int val[10] = {0,0,0,0,0,0,0,0,0,0};
	int lazy;
	bool isLazy;
};

int dat[MAXN];
seg tree[MAXN * 3];

void push_up(int i) {
	for (int j = 0; j < 10; j++)
		tree[i].val[j] =
		tree[i << 1].val[j] +
		tree[i << 1 | 1].val[j];
}

void apply(int i, int lazy) {
	lazy %= 10;
	rotate(tree[i].val, tree[i].val + (10-lazy), tree[i].val + 10);
	tree[i].lazy += lazy;
	tree[i].lazy %= 10;
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
		tree[i].val[ dat[l]]++;
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

int query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		int res = 0;
		for (int j = 0; j < 10; j++)
			res += tree[i].val[j] * j;
		return res;
	}
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; string s; cin >> n >> m>>s;
	for (int i = 0; i < n; i++)
		dat[i] = s[i] - '0';
	build(0, n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--;
		printf("%d\n", query(a, b));
		update(a, b, 1);
	}
	cin >> n;
}
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

#define MAXN 200001

//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	char lazy;
	vector<vector<int>> cnt;
	bool isLazy;
};

seg tree[MAXN * 3];

void push_up(int i) {
	int lc = i << 1, rc = lc + 1;
	for (int l = 0; l < 4; l++) {
		for (int r = l + 1; r <= 4; r++) {
			for (int sp = l + 1; sp < r; sp++) {
				tree[i].cnt[l][r] += min(
					tree[lc].cnt[l][sp],
					tree[rc].cnt[sp][r]
				);
			}
		}
	}
}

void apply(int i, char lazy) {
	int sz = tree[i].r - tree[i].l;
	if (lazy == 'M')
		tree[i].cnt[0][1] = sz;
	if (lazy == 'A')
		tree[i].cnt[1][2] = sz;
	if (lazy == 'K')
		tree[i].cnt[2][3] = sz;
	if (lazy == 'I')
		tree[i].cnt[3][4] = sz;

	tree[i].lazy = lazy;
	tree[i].isLazy = true;
}

void push_down(int i) {
	if (!tree[i].isLazy) return;
	apply(i << 1, tree[i].lazy);
	apply(i << 1 | 1, tree[i].lazy);

	tree[i].isLazy = false;
	tree[i].lazy = 0;
}

vector<vector<int>> empt;

void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	for (int j = 0; j < 4; j++)
	{
		tree[i].cnt.push_back(vector<int>());
		for (int k = 0; k < 5; k++)
			tree[i].cnt[j].push_back(0);
	}
	if (l + 1 == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int l, int r, char x, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, i << 1); update(l, r, x, i << 1 | 1);
	push_up(i);
}

vector<vector<int>>  query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].cnt;
	if (tree[i].r <= l || tree[i].l >= r) return empt;
	push_down(i);
	auto resl = query(l, r, i << 1);
	auto resr = query(l, r, i << 1 | 1);
	vector<vector<int>> res;
	int lc = i << 1, rc = lc + 1;
	for (int l = 0; l < 4; l++) {
		res.push_back(vector<int>());
		for(int k=0;k<=4;k++)
			res[l].push_back(0);
		for (int r = l + 1; r <= 4; r++) {
			for (int sp = l + 1; sp < r; sp++) {
				res[l][r] += min(
					resl[l][sp],
					resr[sp][r]
				);
			}
		}
	}
	return res;
}


int main() {
	for (int j = 0; j < 4; j++)
	{
		empt.push_back(vector<int>());
		for (int k = 0; k < 5; k++)
			empt[j].push_back(0);
	}

	int n, q; scanf("%d %d", &n, &q);
	build(0, n);
	if (q <= 10)
		printf("lfkjglkfdsg");
	for (int i = 0; i < q; i++) {
		int op, l, r; scanf("%d %d %d", &op, &l, &r);
		l--;
		if (op == 1) {
			char c; scanf(" %c", &c);
			update(l, r, c);
		}
		else {
			auto res = query(l, r);
			printf("%d\n", res[0][4]);
		}
	}
	cin >> n;
}
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
using namespace std;

#define memeset memset

template<typename T>
inline T INF(T a) { return a == -1 ? INT_MAX : a; }
inline int _INF(int a) { return a == INT_MAX ? -1 : a; }

template<typename T>
inline T INF_MAX(T a, T b) { return INF(a) > INF(b) ? a : b; }

template<typename T>
inline T INF_MIN(T a, T b) { return INF(a) < INF(b) ? a : b; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100001

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
	tree[i].val = lazy * (tree[i].r - tree[i].l);
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

int c[MAXN];
int d[MAXN];

int sortByC[MAXN];
int sortByD[MAXN];

bool predC(int a, int b) {
	return c[a] < c[b];
}

bool predD(int a, int b) {
	return d[a] < d[b];
}

bool currCake[MAXN];

int main() {
	int R, C; scan(R); scan(C);
	int lastL = -100; int lastR = C+100;

	for (int i = 0; i < R; i++) {
		scan(c[i]); scan(d[i]);
		c[i]--;
		sortByC[i] = i;
		sortByD[i] = i;
	}

	sort(sortByC, sortByC + R, predC);
	sort(sortByD, sortByD + R, predD);

	build(0, MAXN);

	int cIdx = 0, dIdx = 0;
	int cLoc, dLoc;

	for (int i = 0; i < C; i++) {
		int r, s; scan(r); scan(s);
		r--;
		while (cIdx < R && c[cLoc = sortByC[cIdx]] <= i) {
			currCake[cLoc] = true;
			update(cLoc, cLoc + 1, 1);
			cIdx++;
		}
		while (dIdx < R && d[dLoc = sortByD[dIdx]] <= i) {
			currCake[dLoc] = false;
			update(dLoc, dLoc + 1, 0);
			dIdx++;
		}

		if (query(r, s) != (s - r)
			|| query(0, r) != 0
			|| query(s, C) != 0) {
			for (int j = 0; j < R; j++)
				if (currCake[j] != (j >= r && j < s)) {
					cout << "nonsense" << endl;
					cout << j + 1 << " " << i + 1 << endl;
					return 0;
				}
		}
	}

	for (int i = 0; i < R; i++)
	{
		if (d[i] <= lastL || c[i] >= lastR)
		{
			cout << "nonsense" << endl;
			cout << "unconnected" << endl;
			return 0;
		}
		lastL = c[i], lastR = d[i];
	}
	cout << "sense" << endl;
}
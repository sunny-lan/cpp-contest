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

#define MAXN 100000
//RANGES ARE EXCLUSIVE: [L,R)

struct seg {
	int l, r;
	ll val;
	ll lazy;
	bool isLazy;
};

ll dat[MAXN * 2];
seg tree[MAXN * 6];

void push_up(int i) {
	tree[i].val = max(
		tree[i << 1].val,
		tree[i << 1 | 1].val);
}

void apply(int i, ll lazy) {
	tree[i].val += lazy;
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

int query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return max(query(l, r, i << 1), query(l, r, i << 1 | 1));
}

unordered_map<int, int> ord;

int sortedEnding[MAXN];
int sortedStart[MAXN];

int a[MAXN];
int b[MAXN];

bool pred1(int x, int y) {
	return b[x] < b[y];
}

bool pred2(int x, int y) {
	return a[x] < a[y];
}

int main() {
	int t; scan(t);
	for (int testCase = 1; testCase <= t; testCase++) {
		memset(a, 0x3f, sizeof a);
		memset(b, 0x3f, sizeof b);
		int n; scan(n);

		vector<int> cust;

		for (int i = 0; i < n; i++) {
			scan(a[i]); scan(b[i]);
			b[i]++;
			sortedEnding[i] = i;
			sortedStart[i] = i;
			cust.push_back(a[i]), cust.push_back(b[i]);
		}
		sort(cust.begin(), cust.end());

		int m = unique(cust.begin(), cust.end()) - cust.begin();

		for (int i = 0; i < m; i++)
			ord[cust[i]] = i;

		build(0, m);
		for (int i = 0; i < n; i++) {
			a[i] = ord[a[i]];
			b[i] = ord[b[i]];
			update(a[i], b[i], 1);
		}

		sort(sortedEnding, sortedEnding + n, pred1);
		sort(sortedStart, sortedStart + n, pred2);

		int maxi = 0;

		int cnt = 0;
		int i = 0;
		int j = 0;
		for (int curr = 0; curr < m; curr++) {
			while (i<n && a[sortedStart[i]] <= curr ) {
				update(a[sortedStart[i]], b[sortedStart[i]], -1);
				i++, cnt++;
			}
			while (j<n && b[sortedEnding[j]] <= curr )
				j++, cnt--;

			maxi = max(maxi, query(curr, m) + cnt);
		}

		cout << "Case " << testCase << ": " << maxi << endl;
	}
	cin >> t;
}
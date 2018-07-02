#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_map>
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;

#define MAXN 500000
#define MAXN2 MAXN*2
#define MOD 1000000007

struct seg {
	int l, r;
	ll sum, maxi;
	ll lazy;
	bool isLazy;

	seg* left; seg* right;
};

seg tree[MAXN2 * 3];
ll locs[MAXN * 2];

void push_up(int i) {
	tree[i].sum =
		tree[(i << 1)].sum +
		tree[(i << 1) + 1].sum;
	tree[i].maxi = max(
		tree[(i << 1)].maxi,
		tree[(i << 1) + 1].maxi);
}

void apply(int i, ll lazy) {
	tree[i].maxi = lazy;
	tree[i].sum = lazy*(locs[tree[i].r] - locs[tree[i].l]);
	tree[i].lazy = lazy;
	tree[i].isLazy = true;
}

void push_down(int i) {
	if (!tree[i].isLazy)return;
	apply((i << 1), tree[i].lazy);
	apply((i << 1) + 1, tree[i].lazy);

	tree[i].isLazy = false;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	if (l == r - 1)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, (i << 1)); build(mid, r, (i << 1) + 1);
	push_up(i);

	//fur debugging
	tree[i].left = &tree[i << 1];
	tree[i].right = &tree[i << 1 | 1];
}

void update(int l, int r, ll x, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, (i << 1)); update(l, r, x, (i << 1) + 1);
	push_up(i);
}

ll querySum(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].sum;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return querySum(l, r, (i << 1)) + querySum(l, r, (i << 1) + 1);
}

ll queryMax(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].maxi;
	if (tree[i].r <= l || tree[i].l >= r) return 0;
	push_down(i);
	return max(queryMax(l, r, (i << 1)), queryMax(l, r, (i << 1) + 1));
}

unordered_map<ll, int> ord;
pair<pair<ll, ll>, int> queries[MAXN];

int main() {
	int n; scan(n);

	for (int i = 0; i < n; i++) {
		ll s, l; int w; scan(s); scan(l); scan(w);
		locs[i << 1] = --s;
		locs[(i << 1) + 1] = s + l;
		queries[i] = { { s, s + l },w };
	}
	sort(locs, locs + n * 2);
	int end = unique(locs, locs + n * 2) - locs;
	for (int i = 0; i < end; i++)
		ord[locs[i]] = i;

	build(0, end);

	ll tot = 0;
	for (int i = 0; i < n; i++) {
		ll bl = queries[i].first.first,
			br = queries[i].first.second;
		int l = ord[bl],
			r = ord[br];
		int w = queries[i].second;

		ll maxi = queryMax(l, r);
		ll sum = querySum(l, r);
		ll area = maxi*(br - bl);

		tot += area - sum;
		update(l, r, maxi + w);
	}

	cout << tot%MOD << endl;
	cin >> n;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100001

typedef pair<ll, int> pli;

struct seg {
	int l, r;
	pli val;
	pli lazy;
	bool isLazy;
};

seg tree[MAXN * 3];

void push_up(int i) {
	seg &a = tree[i << 1],
		&b = tree[i << 1 | 1],
		&c = tree[i];
	c.val = max(a.val, b.val);
}


pli f;
void apply(int i, pli lazy) {
	tree[i].val = lazy;
	tree[i].lazy = lazy;
	tree[i].isLazy = true;
}

void push_down(int i) {
	if (!tree[i].isLazy) return;
	apply(i << 1, tree[i].lazy);
	apply(i << 1 | 1, tree[i].lazy);

	tree[i].isLazy = false;
}

void build(int l, int r, int i = 1) {
	tree[i].l = l; tree[i].r = r;
	if (l+1 == r) {
		tree[i].val = f;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i << 1); build(mid, r, i << 1 | 1);
	push_up(i);
}

void update(int l, int r, pli x, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r) {
		apply(i, x);
		return;
	}
	if (tree[i].r <= l || tree[i].l >= r)return;
	push_down(i);
	update(l, r, x, i << 1); update(l, r, x, i << 1 | 1);
	push_up(i);
}

pli query(int l, int r, int i = 1) {
	if (tree[i].l >= l && tree[i].r <= r)
		return tree[i].val;
	if (tree[i].r <= l || tree[i].l >= r) return f;
	push_down(i);
	return max(query(l, r, i << 1), query(l, r, i << 1 | 1));
}

ll c[MAXN];

vector<pair<int, ll>> children[MAXN];

ll best[MAXN];
ll dist[MAXN];

vector<pli> chain[MAXN];

void dfs(int i) {
	int l = query(0, c[i]).second;
	best[i] = best[l] + c[i] * (dist[i] - dist[l]);

	chain[c[i]].push_back({ dist[i], i });
	update(c[i], c[i] + 1, chain[c[i]].back());
	for (auto child : children[i]) {
		int j = child.first; ll d = child.second;
		dist[j] = dist[i] + d;
		dfs(j);
	}

	chain[c[i]].pop_back();
	update(c[i], c[i] + 1, chain[c[i]].empty() ? f : chain[c[i]].back());
}

int main() {
	int n; scan(n);
	f = { 0,n-1 };
	build(0, MAXN);
	c[n - 1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int p; ll d; scan(p);  scan(d); scan(c[i]);
		children[--p].push_back({ i, d });
	}

	dfs(n - 1);

	for (int i = 0; i < n - 1; i++)
		printf("%lld\n", best[i]);
}
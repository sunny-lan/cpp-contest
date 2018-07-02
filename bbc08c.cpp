#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXK 51

struct seg {
	int l, r;
	bitset<MAXK> mask;
	set<int> locs[MAXK];
	unordered_map<int, int> cnt;
};

seg tree[MAXN * 3];

int v[MAXN];

void build(int l, int r, int i = 1) {
	tree[i].l = l, tree[i].r = r;
	for(int j = l; j < r; j++)
	{
		tree[i].locs[v[j]].insert(j);
		tree[i].mask[v[j]] = 1;
		tree[i].cnt[v[j]]++;
	}
	if(r == l + 1) return;
	int mid = (l + r) / 2;
	build(l, mid, i * 2), build(mid, r, i * 2 + 1);
}

void update(int p, int x, int i = 1) {
	if(p < tree[i].l || p >= tree[i].r)
		return;
    if(--tree[i].cnt[v[p]]==0)
        tree[i].mask[v[p]]=0;
    tree[i].locs[x].erase(p);
    tree[i].locs[x].insert(p);

	if(tree[i].l == tree[i].r - 1)
		return;
}

int n, k, m;

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]),v[i]--;
}

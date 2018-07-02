#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXK 51

struct seg {
	int l, r;
	bitset<MAXK> mask;
	set<int> locs[MAXK];
	unordered_map<int, int> cnt;
	int mini = -1;
};

seg tree[MAXN * 3];

int v[MAXN];
int n, k, m;

void update(int p, int x, int i = 1) {
	if(p < tree[i].l || p >= tree[i].r)
		return;
	if(v[p] != -1) {
		if(--tree[i].cnt[v[p]] == 0)
			tree[i].mask[v[p]] = 0;
		tree[i].locs[v[p]].erase(p);
	}
	tree[i].locs[x].insert(p);
	tree[i].cnt[x]++;
	if(tree[i].l == tree[i].r - 1) {
		if(tree[i].mask.count() == k)
			tree[i].mini = 1;
		return;
	}
	update(p, x, i * 2), update(p, x, i * 2 + 1);
	tree[i].mini = -1;
	if(tree[i * 2].mini != -1)
		tree[i].mini = min(tree[i * 2].mini, tree[i].mini);
	if(tree[i * 2 + 1].mini != -1)
		tree[i].mini = min(tree[i * 2 + 1].mini, tree[i].mini);
	tree[i].mask = tree[i * 2].mask | tree[i * 2 + 1].mask;
	if( tree[i].mini == -1 && tree[i].mask.count() == k) {
		for(int j = 0; j < k; j++)
			tree[i].mini = max(tree[i].mini,
							   min(tree[i * 2].r - *tree[i * 2].locs[j].rbegin(),
								   *tree[i * 2 + 1].locs[j].begin()));
	}
}


int main() {
	memset(v, -1, sizeof v);
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		update(i, x - 1);
	}
	for(int i = 0; i < m; i++) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int p, x;
			scanf("%d %d", &p, &x);
			update(p - 1, x - 1);
		} else {
			printf("%d\n", tree[1].mini);
		}
	}
}

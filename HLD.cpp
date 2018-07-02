#include <list>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define MAXN 50000
list<pii> adj[MAXN];

int cnt = 0, ind = 0;

int top[MAXN], chain[MAXN];
int par[MAXN], special[MAXN], dep[MAXN];
int arr[MAXN], pos[MAXN];

//segment tree for rmq
struct seg { int l, r, v; };
seg tree[3 * MAXN];
void build(int r, int n = 1, int l = 0) {
	tree[n].l = l; tree[n].r = r;
	if (l == r)
		tree[n].v = arr[l];
	else {
		int m = (l + r) / 2;
		build(m, n << 1, l);
		build(r, n << 1 | 1, m + 1);
		tree[n].v = max(tree[n << 1].v, tree[n << 1 | 1].v);
	}
}
void update(int idx, long long val, int n = 1) {
	if (tree[n].l == tree[n].r)
		tree[n].v += val;
	else {
		int m = (tree[n].l + tree[n].r) / 2;
		if (tree[n].l <= idx && idx <= m)
			update(idx, val, n << 1);
		else
			update(idx, val, n << 1 | 1);
		tree[n].v = max(tree[n << 1].v, tree[n << 1 | 1].v);
	}
}
int query(int l, int r, int n = 1) {
	if (r < tree[n].l || l > tree[n].r)
		return 0;
	if (r >= tree[n].r && l <= tree[n].l)
		return tree[n].v;
	return max(query(l, r, n << 1), query(l, r, n << 1 | 1));
}

//finds parent, subtree size, and depth of each node
int dfs(int n, int prev = -1, int d = 0) {
	int sub = 1;
	par[n] = prev;
	dep[n] = d;
	int m = -1;
	for (pii i : adj[n]) {
		if (i.first != prev) {
			int sz = dfs(i.first, n, d + 1);
			sub += sz;
			if (sz > m)
				special[n] = i.first, m = sz;
		}
	}
	return sub;
}

//decomposes tree
void hld(int n, int prev = -1, int cost = -1) {
	//if a new chain is made, sets current node as its head
	if (top[cnt] == -1)
		top[cnt] = n;
	chain[n] = cnt;

	//assigns node a position in segment tree
	//the edge associated with a node connects it to its parent
	pos[n] = ind;
	arr[ind++] = cost;

	//if the current node is a leaf node, stops
	if (special[n] == -1)
		return;

	//continues current chain down path of special child
	hld(special[n], n, cost);

	//starts new chains for all other children
	for (pii i : adj[n]) {
		if (i.first != prev && i.first != special[n]) {
			++cnt;
			hld(i.first, n, i.second);
		}
	}
}

//queries the tree
int query_up(int u, int v) {
	int res = -1;

	//moves up the tree until the two nodes are part of the same chain
	while (chain[u] != chain[v]) {
		//queries the path from the node with the greater depth to the head of its chain
		//then, changes that node to the parent of the head of its chain
		if (dep[top[chain[u]]] < dep[top[chain[v]]])
			swap(u, v);
		res = max(res, query(pos[top[chain[u]]], pos[u]));
		u = par[top[chain[u]]];
	}

	//now that the two nodes are part of the same chain, queries the path between them
	if (pos[u] > pos[v])
		swap(u, v);
	return max(res, query(pos[u] + 1, pos[v]));
}

//updates the tree
void update_tree(int u, int v, int val) {
	if (dep[u] < dep[v])
		swap(u, v);
	update(pos[u], v);
}
int main() {
	memset(special, -1, sizeof special);
	memset(top, -1, sizeof top);
	return 0;
}
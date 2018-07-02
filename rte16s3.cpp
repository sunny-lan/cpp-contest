#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

#define MAXN 6001
#define MAXM 6001

using namespace std;

int n;

vector<pair<int, int>> adjlist[MAXN];
int disjoint[MAXN];

int treesize[MAXN];
int special[MAXN];
int weight[MAXN];
int parent[MAXN];
int ptr[MAXN];
int height[MAXN];
int tree[MAXN * 2];
bool visited[MAXN];
int best, tmpspecial;

void dfs(int i) {
	visited[i] = true;
	treesize[i] = 1;
	best = -1;
	tmpspecial = -1;
	for (pair<int, int> adj : adjlist[i]) {
		if (adj.first == parent[i])
			continue;

		parent[adj.first] = i;
		weight[adj.first] = adj.second;
		height[adj.first] = height[i] + 1;
		dfs(adj.first);
		treesize[i] += treesize[adj.first];

		if (treesize[adj.first] > best) {
			best = treesize[adj.first];
			tmpspecial = adj.first;
		}
	}
	special[i] = tmpspecial;
}

int curridx = 0;
void hld(int i) {
	tree[n + curridx] = weight[i];
	ptr[i] = curridx;
	curridx++;
	if (special[i] != -1) {
		disjoint[special[i]] = disjoint[i];
		hld(special[i]);
	}

	for (pair<int, int> adj : adjlist[i]) {
		if (adj.first != special[i] && adj.first != parent[i])
			hld(adj.first);
	}
}

void construct() {
	for (int i = n - 1; i >= 0; i--)
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

int querylst(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res += tree[l++];
		if (r & 1)
			res += tree[--r];
	}
	return res;
}

int query(int a, int b) {
	if (disjoint[a] == disjoint[b]) {
		if (height[a] > height[b])
			return query(b, a);
		return querylst(ptr[a], ptr[b] + 1);
	}

	if (height[disjoint[a]] > height[disjoint[b]])
		return query(parent[disjoint[a]], b) + querylst(ptr[disjoint[a]], ptr[a] + 1);

	if (height[disjoint[b]] >= height[disjoint[a]])
		return query(a, parent[disjoint[b]]) + querylst(ptr[disjoint[b]], ptr[b] + 1);

	//should never happen
	printf("fuck\n");
	return INT_MAX;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		disjoint[i] = i;

	}

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adjlist[a].push_back(make_pair(b, c));
		adjlist[b].push_back(make_pair(a, c));
	}

	dfs(0);

	weight[0] = -1;
	hld(0);
	construct();

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b) + 1);
	}
	//cin >> n;
}
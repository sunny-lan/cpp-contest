#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

#define MAXN 50001
#define MAXM 100001

using namespace std;

struct edge {
	int a;
	int b;
	int c;
	bool operator <(const edge& b) const {
		return c > b.c;
	}
};

int n, m;

vector<edge> all(MAXM);
vector<vector<pair<int, int>>> adjlist(MAXN);
priority_queue<edge> q;
int disjointMST[MAXN];

int find(int x) {
	if (disjointMST[x] == x)
		return x;
	return disjointMST[x] = find(disjointMST[x]);
}

bool cmpSet(int x, int y) {
	return find(x) == find(y);
}

void merge(int x, int y) {
	disjointMST[find(x)] = disjointMST[find(y)];
}

int treesize[MAXN];
int special[MAXN];
int weight[MAXN];
int parent[MAXN];
int ptr[MAXN];
int height[MAXN];
int disjoint[MAXN];
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
		tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

int querylst(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = max(tree[l++], res);
		if (r & 1)
			res = max(tree[--r], res);
	}
	return res;
}

int query(int a, int b) {
	if (disjoint[a] == disjoint[b]) {
		if (height[a] > height[b])
			return query(b, a);
		return querylst(ptr[a], ptr[b]+1);
	}

	if (height[disjoint[a]] > height[disjoint[b]])
		return max(query(parent[disjoint[a]], b), querylst(ptr[disjoint[a]], ptr[a] + 1));

	if (height[disjoint[b]] > height[disjoint[a]])
		return max(query(a, parent[disjoint[b]]), querylst(ptr[disjoint[b]], ptr[b] + 1));

	//should never happen
	return INT_MAX;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		disjointMST[i] = i;
		disjoint[i] = i;
	}

	for (int i = 0; i < m; i++) {
		edge e;
		scanf("%d%d%d", &e.a, &e.b, &e.c);
		e.a--;
		e.b--;
		q.push(e);
		all.push_back(e);
	}

	//a tree needs n-1 edges. But to have the second best tree you need n edges
	if (m < n) {
		cout << -1 << endl;
		return 0;
	}

	int mst = 0;

	while (!q.empty()) {
		edge next = q.top();
		q.pop();
		if (!cmpSet(next.a, next.b)) {
			merge(next.a, next.b);
			adjlist[next.a].push_back(make_pair(next.b, next.c));
			adjlist[next.b].push_back(make_pair(next.a, next.c));
			mst += next.c;
		}
	}

	dfs(0);

	//check if tree is connected
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	weight[0] = -1;
	hld(0);
	construct();

	int mini = INT_MAX;
	edge replaced;

	for (edge e : all) {
		int remove = query(e.a, e.b);
		int add = e.c;
		int newmst = mst - remove + add;
		//if already in tree
		if (newmst == mst)
			continue;
		if (newmst < mini) {
			mini = newmst;
			replaced = e;
		}
	}

	//cout << "a=" << replaced.a << ",b=" << replaced.b << endl;

	if (mini == INT_MAX)
		cout << -1 << endl;
	else
		cout << mini << endl;

	//cin >> n;
}
//heavy light

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

// n dimension psa

#define MAXN 12
#define MAXP 11000000

#define NUM int

int n;
int l[MAXN];
int base[MAXN];

int p[MAXN];
NUM v;

NUM bit[MAXP];
inline void update(int di, int pt) {
	if (di == n)
		bit[pt] += v;
	else
		for (int x = p[di]; x <= l[di]; x += x&-x)
			update(di + 1, pt + base[di] * (x - 1));
}

inline NUM query(int di, int pt) {
	if (di == n)
		return bit[pt];
	else {
		NUM res = 0;
		for (int x = p[di]; x > 0; x -= x&-x)
			res += query(di + 1, pt + base[di] * (x - 1));
		return res;
	}
}

int b[MAXN];

short value[MAXP];

int main() {
	int q; scan(n); scan(q);
	base[0] = 1;
	for (int i = 0; i < n; i++) {
		scan(l[i]);
		base[i + 1] = base[i] * l[i];
	}

	for (int i = 0; i < q; i++) {
		int op; scan(op);
		int idx = 0;
		for (int j = 0; j < n; j++) {
			scan(p[j]);
			idx += (p[j] - 1) * base[j];
		}
		if (op == 1) {
			scan(v);
			int tmp = v;
			v -= value[idx];
			value[idx] = tmp;
			update(0, 0);
		}
		else {
			for (int j = 0; j < n; j++) {
				scan(b[j]);
				p[j]--;
			}
			int res = 0;
			for (int l = 0; l < 1 << n; l++) {
				int mult = 1;
				int bcnt = 0;
				for (int j = 0; j < n; j++)
					if ((l >> j) & 1)
						p[j] = b[j], bcnt++;

				if (bcnt % 2 == (n + 1) % 2)
					mult = -1;
				res += query(0, 0)*mult;
			}
			//if (res < 0)while (true)printf("e");
			printf("%lld\n", res);
		}
	}
	cin >> q;
}

//Sliding rmq

//queue is sorted from min to max, and in order of indexes
//anything at front of queue that is out of sliding window is poped
//whenever a new element is added to the sliding window, 
//the back of queue is popped until it is < than the new elem
deque<pair<int, ll>> q;
q.push_back({ 0,0 });
for (int i = 1; i <= n; i++) {
	ll x; scan(x);
	while (q.front().first < i - k)
		q.pop_front();
	dp[i] = q.front().second + x;
	ptr[i] = q.front().first;
	while (!q.empty() && q.back().second >= dp[i])
		q.pop_back();
	q.push_back({ i, dp[i] });
}

// Cut edges (bridges)

#define MAXN 1001

vector<int> adj[MAXN];

vector<pii> cut;
int disc[MAXN];
int low[MAXN];
bool visited[MAXN];
int vtime = 0;
void _cut_dfs(int i, int j = -1) {
	if (visited[i])return;
	visited[i] = true;
	disc[i] = low[i] = ++vtime;
	int cnt = 0;
	for (int neigh : adj[i]) {
		if (visited[neigh]) {
			if (neigh != j)
				low[i] = min(low[i], disc[neigh]);
		}
		else {
			cnt++;
			_cut_dfs(neigh, i);
			low[i] = min(low[i], low[neigh]);
			if (low[neigh] > disc[i])
				cut.push_back({ i, neigh });
		}
	}
}

void cutedges() {
	for (int i = 0; i < n; i++)if (!visited[i])_cut_dfs(i);
}

// example of mos algorithm

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 100000

typedef pair<int, int> pii;

int a[MAXN];

int ptr[MAXN];
pii qu[MAXN];
int n, bs;
bool pred(int _a, int _b) {
	pii a = qu[_a], b = qu[_b];
	int ba = a.first / bs,
		bb = b.first / bs;
	if (ba == bb)
		return a.second < b.second;
	return ba < bb;
}

int cnt = 0;
int freq[MAXN];

int ans[MAXN];

int main() {
	scanf("%d", &n); bs = sqrt(n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d %d", &qu[i].first, &qu[i].second), ptr[i] = i, qu[i].first--;
	sort(ptr, ptr + q, pred);
	int cl = 0, cr = 0;
	for (int i = 0; i < q; i++) {
		int dl = qu[ptr[i]].first,
			dr = qu[ptr[i]].second;

		while (cr < dr) {
			freq[a[cr]]++;
			if (freq[a[cr]] > 1) {
				if (freq[a[cr]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
			cr++;
		}

		while (cl > dl) {
			cl--;
			freq[a[cl]]++;
			if (freq[a[cl]] > 1) {
				if (freq[a[cl]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
		}

		while (cl < dl) {
			freq[a[cl]]--;
			if (freq[a[cl]] > 0) {
				if (freq[a[cl]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
			cl++;
		}

		while (cr > dr) {
			cr--;
			freq[a[cr]]--;
			if (freq[a[cr]] > 0) {
				if (freq[a[cr]] % 2 == 1)
					cnt--;
				else
					cnt++;
			}
		}
		ans[ptr[i]] = cnt;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}

//fixed line intersection

struct vec2 {
	double x, y;

	vec2(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

struct line {
	vec2 p, q;
	line(vec2 _p=vec2(), vec2 _q=vec2()) {
		p = _p, q = _q;
	}
};

bool inter(line w, line s) {
	double wa = w.q.y - w.p.y,
		wb = w.p.x - w.q.x,
		wc = wa*w.p.x + wb*w.p.y,
		sa = s.q.y - s.p.y,
		sb = s.p.x - s.q.x,
		sc = sa*s.p.x + sb*s.p.y;
	double det = wa*sb - sa*wb;
	if (det == 0)return false;
	double xint = (sb*wc - wb*sc) / det,
		yint = (wa*sc - sa*wc) / det;
	double wlx = min(w.p.x, w.q.x), wrx = max(w.p.x, w.q.x),
		wly = min(w.p.y, w.q.y), wry = max(w.p.y, w.q.y),
		slx = min(s.p.x, s.q.x), srx = max(s.p.x, s.q.x),
		sly = min(s.p.y, s.q.y), sry = max(s.p.y, s.q.y);
	if (xint >= wlx && xint <= wrx && yint >= wly && yint <= wry)
		if (xint >= slx && xint <= srx && yint >= sly && yint <= sry)return true;
	return false;
}
#include <iostream>
#include <vector>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 100000

int n;  // array size

int disjoint[MAXN];

void construct_disjoint() {
	for (int i = 0; i < n; i++)
		disjoint[i] = i;
}

#define combiner(a,b) a+b
#define identity 0
#define MAXN 100000

int tree[2 * MAXN];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) tree[i] = combiner(tree[i << 1], tree[i << 1 | 1]);
}

void modify(int l, int r, int value) {  // set value at position p
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) tree[l++] += value;
		if (r & 1) tree[--r] += value;
	}
}

int querylst(int p) {  // sum on interval [l, r)
	int res = identity;
	for (p += n; p > 1; p >>= 1)
		res += tree[p];
	return res;
}

//hld input
vector<pair<int, int>> adj[MAXN];

int treesize[MAXN]; //stores subtree sizes
int special[MAXN]; //stores special child of each node
int weight[MAXN]; //stores weight connecting each node to parent
int parent[MAXN]; //stores parent node
int ptr[MAXN]; //pointer to position in segtree
int height[MAXN]; // stores distance of node from parent
int disjoint[MAXN]; //used to calculate lca
bool visited[MAXN];

//converts tree to rooted form, and fill in other info
void dfs(int i) {
	visited[i] = true;
	treesize[i] = 1;

	//tracks child with largest tree size
	int best = -1;
	int tmpSpecial = -1;

	for (auto neigh : adj[i]) {
		int j = neigh.first;
		//avoid going to parent
		if (j == parent[i])
			continue;
		parent[j] = i;//set new parent
	    //store weight connecting child to parent
		weight[j] = neigh.second;
		//store height
		height[j] = height[i] + 1;
		dfs(j);
		treesize[i] += treesize[j];

		//check if subtree size is bigger
		if (treesize[j] > best) {
			best = treesize[j];
			tmpSpecial = j;
		}
	}
	special[i] = tmpSpecial;
}

//current pos in segtree
int currIdx = 0;

//decomposes tree
void hld(int i) {
	//store current node into segtree
	tree[n + currIdx] = weight[i];
	ptr[i] = currIdx;
	currIdx++;

	//do special child first, ensuring chain remains continuous in segtree
	if (special[i] != -1) {
		//stores chain id (which is just first node in chain)
		disjoint[special[i]] = disjoint[i];
		hld(special[i]);
	}

	//now do all non special children
	for (auto neigh : adj[i]) {
		int j = neigh.first;
		if (j == special[i] || j == parent[i])continue;
		hld(j);
	}
}

//init hld
void construct() {
	construct_disjoint();
	dfs(0);
	hld(0);
}

void update(int a, int b) {
	// if they are in the same chain
	if (disjoint[a] == disjoint[b]) {
		// make sure smaller index is first
		if (height[a] > height[b])
			return update(b, a);
		// get max from segment tree
		return modify(ptr[a] + 1, ptr[b] + 1, 1);
	}

	// recursive alg:
	// - basically a 2 pointers
	// - query first whichever segment is the furthest from the root

	if (height[disjoint[a]] > height[disjoint[b]])
		return update(parent[disjoint[a]], b), modify(ptr[disjoint[a]], ptr[a] + 1, 1);

	if (height[disjoint[b]] > height[disjoint[a]])
		return update(a, parent[disjoint[b]]), modify(ptr[disjoint[b]], ptr[b] + 1, 1);

	if (height[a] > height[b])
		return update(parent[disjoint[a]], b), modify(ptr[disjoint[a]], ptr[a] + 1, 1);

	if (height[b] > height[a])
		return update(a, parent[disjoint[b]]), modify(ptr[disjoint[b]], ptr[b] + 1, 1);

	return update(parent[disjoint[a]], b), modify(ptr[disjoint[a]], ptr[a] + 1, 1);
}

int query(int a, int b) {
	if (parent[a] == b) {
		return querylst(ptr[a]);
	}
	else {
		return querylst(ptr[b]);
	}
}

vector<pair<pair<int, int>, bool>> edges;

int main() {
	scan(n);

	for (int i = 0; i < n; i++) {
		int a, b, x; scan(a); scan(b); scan(x);
		a--, b--;
		adj[a].push_back({ b, 0 });
		adj[b].push_back({ a, 0 });
		edges.push_back({ {a,b}, x });
	}
	construct();

	int k; scan(k);
	int last = 0;
	for (int i = 0; i < k; i++) {
		int s; scan(s);
		update(last, s);
		last = s;
	}

	for (auto edge : edges) {
		if (edge.second) {

		}
	}
}
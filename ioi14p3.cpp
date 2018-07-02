#include <unordered_set>
using namespace std;

#define MAXN 1501

int cnt[MAXN];

int p[MAXN];

unordered_set<int> cust[MAXN];

int f(int x) {
	if (p[x] == x)return x;
	return p[x] = f(p[x]);
}

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		cnt[i] = n - 1;
		p[i] = i;
		for (int j = 0; j < n; j++)
			if (j != i) cust[i].insert(j);
	}
}

int hasEdge(int u, int v) {
	if (f(u) == f(v))
		return 1;
	cnt[u]--, cnt[v]--;
	cust[u].erase(v), cust[v].erase(u);
	if (cnt[u] == 1) {
		cnt[u]--;
		for (int neigh : cust[u])
			p[f(u)] = p[f(neigh)];
	}

	if (cnt[v] == 1) {
		cnt[v]--;
		for (int neigh : cust[v])
			p[f(v)] = p[f(neigh)];
	}

	return 0;
}
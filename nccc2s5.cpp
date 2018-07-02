#ifndef _MSC_VER

#include <bits/stdc++.h>

#else

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>

#endif // DMOJ
using namespace std;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAXN 2000
#define MAXL 20

int n, m;
vector<pii> adj[MAXN];

int sparse2[MAXL][MAXN * 2];

int count_bits(int x) {
	int cnt = 0;
	while (x = (x >> 1))cnt++;
	return cnt;
}

//finds lca
int query2(int i, int j) {
	if (i > j)return query2(j, i);
	int bsI = count_bits(j - i);
	return min(sparse2[bsI][i], sparse2[bsI][j - (1 << bsI)]);
}

void construct2(const vector<int> &val) {
	int bs = 1, bsI = 0, n = val.size();
	for (int i = 0; i < n; i++)sparse2[bsI][i] = val[i];
	bs <<= 1, bsI++;
	while (bs < n) {
		for (int i = 0; i + bs <= n; i++)
			sparse2[bsI][i] = min(sparse2[bsI - 1][i], sparse2[bsI - 1][i + (bs >> 1)]);
		bs <<= 1, bsI++;
	}
}


int sparsePar[MAXL][MAXN];
int sparse[MAXL][MAXN];
int h[MAXN];
vector<int> tour;
int first[MAXN];

void dfs(int i, int j) {
	sparsePar[0][i] = j;
	first[i] = tour.size(); tour.push_back(h[i]);
	for (pii neigh : adj[i]) {
		int k = neigh.first;
		if (k == j)continue;
		sparse[0][k] = neigh.second;
		h[k] = h[i] + 1;
		dfs(k, i);
		tour.push_back(h[i]);
	}
}

void construct() {
	memset(h, 0, sizeof h);

	tour.clear();

	dfs(n-1, -1);

	int bs = 2, lvl = 1;
	while (bs <= n) {
		for (int i = 0; i < n; i++) {
			int par1 = sparsePar[lvl - 1][i];
			sparsePar[lvl][i] = sparsePar[lvl - 1][par1];
			sparse[lvl][i] = min(sparse[lvl - 1][i], sparse[lvl - 1][par1]);
		}
		bs <<= 1, lvl++;
	}

	construct2(tour);
}

//finds max on path in tree
int query(int a, int b) {
	int mini = INT_MAX;
	while (a != -1 && b != -1 && a != b) {
		int lca = query2(first[a], first[b] + 1);
		if (h[a] > h[b]) {
			int msb = count_bits(h[a] - lca);
			mini = min(mini, sparse[msb][a]);
			a = sparsePar[msb][a];
		}
		else {
			int msb = count_bits(h[b] - lca);
			mini = min(mini, sparse[msb][b]);
			b = sparsePar[msb][b];
		}
	}
	return mini;
}

pair<int, pii> edges[6000];
int ptr[6000];
bool pred(int a, int b) {
	return edges[a].first > edges[b].first;
}

int p[MAXN], rnk[MAXN];
int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

void refresh() {
	for (int i = 0; i < n; i++)p[i] = i, adj[i].clear(), rnk[i]=1;
	sort(ptr, ptr + m, pred);
	for (int i = 0; i < m; i++) {
		auto edge = edges[ptr[i]];
		int u = edge.second.first, pu = find(u),
			v = edge.second.second, pv = find(v);
		if (pu == pv)continue;
		adj[u].push_back({ v, edge.first });
		adj[v].push_back({ u, edge.first });
		if (rnk[pu] > rnk[pv]) swap(pu, pv);
		rnk[pv] += rnk[pu];
		rnk[pu] = 0;
		p[pu] = pv;
	}

	construct();
}

bool visited[MAXN];
void fil(int i) {
	if (visited[i])return;
	visited[i] = true;
	for (pii neigh : adj[i])
			fil(neigh.first);
}

vector<int> roots;

int main() {
	scan(n); scan(m);
	for (int i = 0; i < m; i++) {
		int u, v, z; scan(u); scan(v); scan(z);
		u--, v--;
		edges[i] = { z,{ u,v } };
		ptr[i] = i;
		adj[u].push_back({ v, z });
		adj[v].push_back({ u, z });
	}

	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		edges[m] = { -1, {i,n} };
		ptr[m] = m;
		m++;
		fil(i);
	}

	n++;

	refresh();

	int q; scan(q);
	for (int i = 0; i < q; i++) {
		int op; scan(op);
		if (op == 1) {
			int e; scan(e); e--;
			scan(edges[e].first);
			refresh();
		}
		else {
			int a, b, w; scan(a); scan(b); scan(w);
			a--, b--;
			int mini = query(a, b);
			if (mini >= w)printf("1\n"); else printf("0\n");
		}
	}
	cin >> q;
}
#ifdef DMOJ

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//NOTE: MACRO DOES NOT WORK WITH NEGATIVE NUMBERS
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define MAXN 50001
#define MAXM 100001
#define MAXL 20

typedef pair<pii, int> edge;

edge edges[MAXM];
bool pred(const edge& a,const edge& b) {
	return a.second < b.second;
}

int p[MAXN];
int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

int n, m;
vector<pii> adj[MAXN];

int sparse2[MAXL][MAXN * 2];

int cache1[MAXN * 2];

inline int count_bits(int x) {
	if (x == 0)return 0;
	int &cnt = cache1[x];
	if (cnt)return cnt;
	while (x = (x >> 1))cnt++;
	return cnt;
}

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
	int bs = 2, lvl = 1;
	while (bs < n) {
		for (int i = 0; i < n; i++) {
			int par1 = sparsePar[lvl - 1][i];
			sparsePar[lvl][i] = sparsePar[lvl - 1][par1];
			sparse[lvl][i] = max(sparse[lvl - 1][i], sparse[lvl - 1][par1]);
		}
		bs <<= 1, lvl++;
	}

	construct2(tour);
}

unordered_map<int, int> cache[MAXN];

int query(int a, int b) {
	if (a > b)return query(b, a);
	if (cache[a].find(b) != cache[a].end())
		return cache[a][b];

	int maxi = 0;
	while (a != b) {
		int lca = query2(first[a], first[b] + 1);
		if (h[a] > h[b]) {
			int msb = count_bits(h[a] - lca);
			maxi = max(maxi, sparse[msb][a]);
			a = sparsePar[msb][a];
		}
		else {
			int msb = count_bits(h[b] - lca);
			maxi = max(maxi, sparse[msb][b]);
			b = sparsePar[msb][b];
		}
	}

	cache[a][b] = maxi;

	return maxi;
}


bool mst[MAXM];

int main() {
	scan(n); scan(m);
	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c; scan(a); scan(b); scan(c);
		edges[i] = { { --a,--b }, c };
	}

	sort(edges, edges + m, pred);

	int val = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (cnt == n - 1)break;
		edge e = edges[i];
		pii tmp = e.first;
		int a = tmp.first, b = tmp.second,
			c = e.second,
			pa = find(a), pb = find(b);
		if (pa == pb)continue;
		val += c;
		p[pa] = pb;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		mst[i] = true;
		cnt++;
	}

	if (cnt != n - 1)
	{
		printf("-1\n");
		return 0;
	}

	dfs(0, 0);
	construct();

	int res = INT_MAX;

	for (int i = 0; i < m; i++)if (!mst[i]) {
		int qr = query(edges[i].first.first, edges[i].first.second);
		int newcost = val + edges[i].second - qr;
		if (newcost <= val)continue;
		res = min(res, newcost);
	}

	if (res == INT_MAX || res == val)
		printf("-1\n");
	else
		printf("%d\n", res);
}
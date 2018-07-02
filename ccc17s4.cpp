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

#define MAXN 100001
#define MAXM 200001
#define MAXL 25

int p[MAXN];
int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

bool active[MAXM];
int c[MAXM];
int ptr[MAXM];
int a[MAXM];
int b[MAXM];
bool pred(int a, int b) {
	if (c[a] == c[b])
		return active[a] > active[b];
	return c[a] < c[b];
}

bool mst[MAXM];
int n, m, d;
vector<pii> adj[MAXN];

int sparse2[MAXL][MAXN * 2];

int count_bits(int x) {
	int cnt = 0;
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

int query(int a, int b) {
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
	return maxi;
}


int main() {

	scan(n); scan(m); scan(d);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		scan(a[i]); scan(b[i]); scan(c[i]);
		a[i]--, b[i]--;
		ptr[i] = i;
		if (i < n - 1)
			active[i] = true;
	}
	sort(ptr, ptr + m, pred);
	int maxi = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int idx = ptr[i];
		int ai = a[idx], bi = b[idx];
		int ap = find(ai), bp = find(bi);
		if (ap == bp)continue;
		p[ap] = bp;
		maxi = max(maxi, c[idx] - max(0, c[idx] - d));
		mst[idx] = true;
		if (!active[idx])cnt++;
	}

	for (int i = 0; i < m; i++) if (mst[i]) {
		int tc = active[i] ? 0 : c[i];
		adj[a[i]].push_back({ b[i], tc });
		adj[b[i]].push_back({ a[i], tc });
	}

	sparse[0][0] = 0;
	dfs(0, 0);
	construct();

	for (int i = 0; i < m; i++)if (!mst[i] && active[i]) {
		int ai = a[i], bi = b[i];
		int res = query(ai, bi);
		int alt = max(0, c[i] - d);
		if (res - alt >= maxi)
		{
			cnt--;
			break;
		}
	}

	printf("%d\n", cnt);
}